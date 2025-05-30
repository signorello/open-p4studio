################################################################################
 #  Copyright (C) 2024 Intel Corporation
 #
 #  Licensed under the Apache License, Version 2.0 (the "License");
 #  you may not use this file except in compliance with the License.
 #  You may obtain a copy of the License at
 #
 #  http://www.apache.org/licenses/LICENSE-2.0
 #
 #  Unless required by applicable law or agreed to in writing,
 #  software distributed under the License is distributed on an "AS IS" BASIS,
 #  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 #  See the License for the specific language governing permissions
 #  and limitations under the License.
 #
 #
 #  SPDX-License-Identifier: Apache-2.0
################################################################################


"""
Thrift SAI interface L3 tests
"""
import socket
import sys
from struct import pack, unpack

from switch_utils import *

import sai_base_test
from ptf.mask import Mask
from ptf import config
from ptf.testutils import *
from ptf.packet import *
from ptf.thriftutils import *
from switchsai_thrift.sai_headers import  *

this_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(this_dir, '..'))
from common.utils import *
from bf_switcht_api_thrift.model_headers import *


@group('l3')
class RouteNbrColision(sai_base_test.ThriftInterfaceDataPlane):

    def check_no_traffic(self):
        try:
            send_packet(self, switch_ports[1], str(self.pkt))
            verify_no_other_packets(self)
        except:
            self.cleanup()
            raise
        return True

    def check_forwarded_traffic(self):
        try:
            send_packet(self, switch_ports[1], str(self.pkt))
            verify_packets(self, self.exp_pkt, [switch_ports[0]])
        except:
            self.cleanup()
            raise
        return True

    def check_cpu_traffic(self):
        try:
            exp_pkt = self.pkt.copy()
            cpu_pkt = simple_cpu_packet(
                ingress_port=switch_ports[1],
                packet_type=0,
                ingress_ifindex=0,
                reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_GLEAN,
                ingress_bd=0,
                inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)
            send_packet(self, switch_ports[1], str(self.pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)
            verify_no_other_packets(self, timeout=1)
        except:
            self.cleanup()
            raise
        return True

    def cleanup(self):
        self.remove_route()
        self.remove_nbr()
        self.client.sai_thrift_remove_next_hop(self.nhop1)
        self.client.sai_thrift_remove_router_interface(self.rif_id1)
        self.client.sai_thrift_remove_router_interface(self.rif_id2)
        self.client.sai_thrift_remove_virtual_router(self.vr_id)

    def create_route(self):
        sai_thrift_create_route(self.client, self.vr_id, self.addr_family, self.ip_addr1_subnet, self.ip_mask1, self.rif_id1)

    def remove_route(self):
        sai_thrift_remove_route(self.client, self.vr_id, self.addr_family, self.ip_addr1_subnet, self.ip_mask1, self.rif_id1)

    def create_nbr(self):
        sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)

    def remove_nbr(self):
        sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)

    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        self.vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        self.rif_id1 = sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        self.rif_id2 = sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        self.addr_family = SAI_IP_ADDR_FAMILY_IPV4
        self.ip_addr1 = '10.10.10.1'
        self.ip_addr1_subnet = '10.10.10.1'
        self.ip_mask1 = '255.255.255.255'
        self.dmac1 = '00:11:22:33:44:55'

        self.pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.0.1',
                                    ip_id=105,
                                    ip_ttl=64)
        self.exp_pkt = simple_tcp_packet(eth_dst='00:11:22:33:44:55',
                                        eth_src=router_mac,
                                        ip_dst='10.10.10.1',
                                        ip_src='192.168.0.1',
                                        ip_id=105,
                                        ip_ttl=63)

        self.nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)


        self.create_nbr()
        assert self.check_forwarded_traffic()

        self.create_route()
        assert self.check_forwarded_traffic()

        self.remove_route()
        assert self.check_forwarded_traffic()

        self.create_route()
        assert self.check_forwarded_traffic()

        self.remove_nbr()
        assert self.check_cpu_traffic()

        self.create_nbr()
        assert self.check_forwarded_traffic()

        self.remove_route()
        self.remove_nbr()
        assert self.check_no_traffic()

        self.create_route()
        assert self.check_cpu_traffic()

        self.create_nbr()
        assert self.check_forwarded_traffic()

        self.cleanup()

@group('l3')
class L3IPv4HostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        # send the test packet(s)
        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3RifSubPortTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_SUB_PORT, port1, 0, v4_enabled, v6_enabled, mac, outer_vlan_id=100)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_SUB_PORT, port2, 0, v4_enabled, v6_enabled, mac, outer_vlan_id=200)
        rif_id3 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr2 = '20.20.20.1'
        ip_addr2_subnet = '20.20.20.0'
        ip_mask2 = '255.255.255.0'
        dmac2 = '00:22:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id3, ip_addr2, dmac2)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id3)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id3)

        # send the test packet(s)
        pkt200 = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                dl_vlan_enable=True,
                                vlan_vid=200,
                                ip_ttl=64,
                                pktlen=104)
        exp_pkt_100 = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                dl_vlan_enable=True,
                                vlan_vid=100,
                                ip_ttl=63,
                                pktlen=104)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:22:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63,
                                pktlen=100)
        try:
            send_packet(self, switch_ports[1], str(pkt200))
            verify_packets(self, exp_pkt_100, [switch_ports[0]])
            attr_value = sai_thrift_attribute_value_t(booldata=False)
            attr = sai_thrift_attribute_t(id=SAI_ROUTER_INTERFACE_ATTR_ADMIN_V4_STATE, value=attr_value)
            self.client.sai_thrift_set_router_interface_attribute(rif_id2, attr)
            send_packet(self, switch_ports[1], str(pkt200))
            verify_no_other_packets(self, timeout=1)
            attr_value = sai_thrift_attribute_value_t(booldata=True)
            attr = sai_thrift_attribute_t(id=SAI_ROUTER_INTERFACE_ATTR_ADMIN_V4_STATE, value=attr_value)
            self.client.sai_thrift_set_router_interface_attribute(rif_id2, attr)
            send_packet(self, switch_ports[1], str(pkt200))
            verify_packets(self, exp_pkt_100, [switch_ports[0]])
            pkt200[IP].dst = '20.20.20.1'
            send_packet(self, switch_ports[1], str(pkt200))
            verify_packets(self, exp_pkt, [switch_ports[2]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id3)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id3, ip_addr2, dmac2)
            self.client.sai_thrift_remove_next_hop(nhop2)
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_router_interface(rif_id3)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3IPv4RifCountersClearTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_addr2 = '20.20.20.1'
        ip_addr2_subnet = '20.20.20.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'

        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask1, rif_id2)

        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)

        pkt2 = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt2 = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            in_bytes_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            print "Sending packet port 2 -> port 1 (192.168.0.1 -> 10.10.10.1)"
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            print "Sending packet port 1 -> port 2 (192.168.0.1 -> 20.20.20.1)"
            send_packet(self, switch_ports[0], str(pkt2))
            verify_packets(self, exp_pkt2, [switch_ports[1]])

            # Check counters
            in_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            assert(in_packets == in_packets_pre + 1), 'rif 1 IN packets counter {} != {}'.format(in_packets, in_packets_pre + 1)
            assert((in_bytes - in_bytes_pre) != 0), 'rif 1 IN bytes counter is 0'
            assert(out_packets == out_packets_pre + 1), 'rif 1 OUT packets counter {} != {}'.format(out_packets, out_packets_pre + 1)
            assert((out_bytes - out_bytes_pre) != 0), 'rif 1 OUT bytes counter is 0'

            # Clear octets counters
            cnt_ids = [SAI_ROUTER_INTERFACE_STAT_IN_OCTETS, SAI_ROUTER_INTERFACE_STAT_OUT_OCTETS]
            self.client.sai_thrift_clear_router_interface_stats(rif_id1, cnt_ids, len(cnt_ids))

            # Check counters
            in_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            assert(in_packets == in_packets_pre + 1), 'rif 1 IN packets counter {} != {}'.format(in_packets, in_packets_pre + 1)
            assert(in_bytes == 0), 'rif 1 IN bytes counter is not 0'
            assert(out_packets == out_packets_pre + 1), 'rif 1 OUT packets counter {} != {}'.format(out_packets, out_packets_pre + 1)
            assert(out_bytes == 0), 'rif 1 OUT bytes counter is not 0'

            print "Sending packet port 2 -> port 1 (192.168.0.1 -> 10.10.10.1)"
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            print "Sending packet port 1 -> port 2 (192.168.0.1 -> 20.20.20.1)"
            send_packet(self, switch_ports[0], str(pkt2))
            verify_packets(self, exp_pkt2, [switch_ports[1]])

            # Clear bytes and packets counter
            cnt_ids = [SAI_ROUTER_INTERFACE_STAT_IN_OCTETS,
                       SAI_ROUTER_INTERFACE_STAT_OUT_OCTETS,
                       SAI_ROUTER_INTERFACE_STAT_IN_PACKETS,
                       SAI_ROUTER_INTERFACE_STAT_OUT_PACKETS]
            self.client.sai_thrift_clear_router_interface_stats(rif_id1, cnt_ids, len(cnt_ids))

            # Check counters
            in_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            assert(in_packets == 0), 'rif 1 IN packets counter is not 0'
            assert(in_bytes == 0), 'rif 1 IN bytes counter is not 0'
            assert(out_packets == 0), 'rif 1 OUT packets counter is not 0'
            assert(out_bytes == 0), 'rif 1 OUT bytes counter is not 0'

        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask1, nhop2)
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3IPv4SviRifCountersClearTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        vlan_id = 10
        mac = ''

        vlan_oid = sai_thrift_create_vlan(self.client, vlan_id)
        vlan_member1 = sai_thrift_create_vlan_member(self.client, vlan_oid, port1, SAI_VLAN_TAGGING_MODE_UNTAGGED)

        attr_value = sai_thrift_attribute_value_t(u16=vlan_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port1, attr)

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan_oid, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_addr2 = '20.20.20.1'
        ip_addr2_subnet = '20.20.20.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        mac_action = SAI_PACKET_ACTION_FORWARD

        sai_thrift_create_fdb(self.client, vlan_oid, dmac1, port1, mac_action)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask1, rif_id2)

        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)

        pkt2 = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt2 = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            in_bytes_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets_pre = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            print "Sending packet port 2 -> port 1 (192.168.0.1 -> 10.10.10.1)"
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            print "Sending packet port 1 -> port 2 (192.168.0.1 -> 20.20.20.1)"
            send_packet(self, switch_ports[0], str(pkt2))
            verify_packets(self, exp_pkt2, [switch_ports[1]])

            # Check counters
            in_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            assert(in_packets == in_packets_pre + 1), 'rif 1 IN packets counter {} != {}'.format(in_packets, in_packets_pre + 1)
            assert((in_bytes - in_bytes_pre) != 0), 'rif 1 IN bytes counter is 0'
            assert(out_packets == out_packets_pre + 1), 'rif 1 OUT packets counter {} != {}'.format(out_packets, out_packets_pre + 1)
            assert((out_bytes - out_bytes_pre) != 0), 'rif 1 OUT bytes counter is 0'

            # Clear octets counters
            cnt_ids = [SAI_ROUTER_INTERFACE_STAT_IN_OCTETS, SAI_ROUTER_INTERFACE_STAT_OUT_OCTETS]
            self.client.sai_thrift_clear_router_interface_stats(rif_id1, cnt_ids, len(cnt_ids))

            # Check counters
            in_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            assert(in_packets == in_packets_pre + 1), 'rif 1 IN packets counter {} != {}'.format(in_packets, in_packets_pre + 1)
            assert(in_bytes == 0), 'rif 1 IN bytes counter is not 0'
            assert(out_packets == out_packets_pre + 1), 'rif 1 OUT packets counter {} != {}'.format(out_packets, out_packets_pre + 1)
            assert(out_bytes == 0), 'rif 1 OUT bytes counter is not 0'

            print "Sending packet port 2 -> port 1 (192.168.0.1 -> 10.10.10.1)"
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            print "Sending packet port 1 -> port 2 (192.168.0.1 -> 20.20.20.1)"
            send_packet(self, switch_ports[0], str(pkt2))
            verify_packets(self, exp_pkt2, [switch_ports[1]])

            # Clear bytes and packets counter
            cnt_ids = [SAI_ROUTER_INTERFACE_STAT_IN_OCTETS,
                       SAI_ROUTER_INTERFACE_STAT_OUT_OCTETS,
                       SAI_ROUTER_INTERFACE_STAT_IN_PACKETS,
                       SAI_ROUTER_INTERFACE_STAT_OUT_PACKETS]
            self.client.sai_thrift_clear_router_interface_stats(rif_id1, cnt_ids, len(cnt_ids))

            # Check counters
            in_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[0]
            out_bytes = sai_thrift_read_rif_counters(self.client, rif_id1)[1]
            in_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[2]
            out_packets = sai_thrift_read_rif_counters(self.client, rif_id1)[3]
            assert(in_packets == 0), 'rif 1 IN packets counter is not 0'
            assert(in_bytes == 0), 'rif 1 IN bytes counter is not 0'
            assert(out_packets == 0), 'rif 1 OUT packets counter is not 0'
            assert(out_bytes == 0), 'rif 1 OUT bytes counter is not 0'

        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask1, nhop2)
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            sai_thrift_delete_fdb(self.client, vlan_oid, dmac1, port1)
            self.client.sai_thrift_remove_vlan_member(vlan_member1)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port1, attr)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_vlan(vlan_oid)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
@disabled
# this is to test ipv4_local_host feature, supported only in A0 profile.Hence not enabled by default.
class L3IPv4LocalRemoteHostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '20.20.20.1'
        ip_addr1_subnet = '10.10.10.1'
        ip_mask1 = '255.255.255.255'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr2 = '10.10.10.1'
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id1)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr2, dmac1)

        # send the test packet(s)
        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            # verify packet routable via /32 installed from nbr
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])

            # verify packet routable via /32 installed from route
            self.client.sai_thrift_remove_next_hop(nhop2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr2, dmac1)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])

        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)


@group('l3')
class L3IPv4MtuTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 172.17.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''
        vlan_id = 10
        mac_action = SAI_PACKET_ACTION_FORWARD

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac, mtu=2000)

        vlan_oid = sai_thrift_create_vlan(self.client, vlan_id)
        vlan_member1 = sai_thrift_create_vlan_member(self.client, vlan_oid, port3, SAI_VLAN_TAGGING_MODE_UNTAGGED)
        attr_value = sai_thrift_attribute_value_t(u16=vlan_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port3, attr)
        rif_id3 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan_oid, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '172.17.10.1'
        ip_addr1_subnet = '172.17.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        ip_addr3 = '192.17.10.1'
        ip_addr3_subnet = '192.17.10.0'
        ip_mask3 = '255.255.255.0'
        dmac3 = '00:11:22:33:44:66'
        sai_thrift_create_fdb(self.client, vlan_oid, dmac3, port3, mac_action)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id3, ip_addr3, dmac3)
        nhop3 = sai_thrift_create_nhop(self.client, addr_family, ip_addr3, rif_id3)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr3_subnet, ip_mask3, rif_id3)

        # send the test packet(s)
        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='172.17.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64,
                                pktlen=1900)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='172.17.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63,
                                pktlen=1900)
        vlan_pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:23',
                                ip_dst='192.17.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64,
                                pktlen=1900)
        vlan_exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:66',
                                eth_src=router_mac,
                                ip_dst='192.17.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63,
                                pktlen=1900)
        try:
            # set initial mtu to 9100
            attr_value = sai_thrift_attribute_value_t(u32=9100)
            attr = sai_thrift_attribute_t(id=SAI_ROUTER_INTERFACE_ATTR_MTU, value=attr_value)
            self.client.sai_thrift_set_router_interface_attribute(rif_id1, attr)
            self.client.sai_thrift_set_router_interface_attribute(rif_id3, attr)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            # update mtu of rif1
            attr_value = sai_thrift_attribute_value_t(u32=1500)
            attr = sai_thrift_attribute_t(id=SAI_ROUTER_INTERFACE_ATTR_MTU, value=attr_value)
            self.client.sai_thrift_set_router_interface_attribute(rif_id1, attr)
            send_packet(self, switch_ports[1], str(pkt))
            verify_no_packet(self, exp_pkt, switch_ports[0], timeout=1)

            send_packet(self, switch_ports[1], str(vlan_pkt))
            verify_packets(self, vlan_exp_pkt, [switch_ports[2]])
            # update mtu of rif3
            attr_value = sai_thrift_attribute_value_t(u32=1500)
            attr = sai_thrift_attribute_t(id=SAI_ROUTER_INTERFACE_ATTR_MTU, value=attr_value)
            self.client.sai_thrift_set_router_interface_attribute(rif_id3, attr)
            send_packet(self, switch_ports[1], str(vlan_pkt))
            verify_no_packet(self, vlan_exp_pkt, switch_ports[2], timeout=1)

            # remove rif 1, rif3 should not be affected
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_router_interface(rif_id1)
            send_packet(self, switch_ports[1], str(vlan_pkt))
            verify_no_packet(self, vlan_exp_pkt, switch_ports[2], timeout=1)
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr3_subnet, ip_mask3, rif_id3)
            self.client.sai_thrift_remove_next_hop(nhop3)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id3, ip_addr3, dmac3)
            sai_thrift_delete_fdb(self.client, vlan_oid, dmac3, port3)

            self.client.sai_thrift_remove_router_interface(rif_id3)
            self.client.sai_thrift_remove_vlan_member(vlan_member1)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port3, attr)

            self.client.sai_thrift_remove_vlan(vlan_oid)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3IPv4HostDropTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 172.17.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '172.17.10.1'
        ip_addr1_subnet = '172.17.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, 0, packet_action=SAI_PACKET_ACTION_DROP)

        # send the test packet(s)
        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='172.17.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='172.17.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            send_packet(self, switch_ports[1], str(pkt))
            verify_no_packet(self, exp_pkt, switch_ports[0])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3IPv4LpmTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        nhop_ip1 = '20.20.20.1'
        nhop_ip1_subnet = '20.20.20.0'
        ip_mask2 = '255.255.255.0'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop1)
        sai_thrift_create_route(self.client, vr_id, addr_family, nhop_ip1_subnet, ip_mask2, rif_id1)

        # send the test packet(s)
        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, nhop_ip1_subnet, ip_mask2, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3IPv6HostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (2000::1 -> 3000::1)"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV6
        ip_addr1 = '1234:5678:9abc:def0:4422:1133:5577:99aa'
        ip_addr1_subnet = '1234:5678:9abc:def0:4422:1133:5577:0'
        ip_mask1 = 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        link_local_ip = 'FE80::1:100'
        ip_addr2_subnet = '1234:5678:9abc::5555:0'
        dmac2 = '00:11:22:55:55:00'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, link_local_ip, dmac2)
        link_local_nhop = sai_thrift_create_nhop(self.client, addr_family, link_local_ip, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask1, link_local_nhop)

        # send the test packet(s)
        pkt = simple_tcpv6_packet( eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99aa',
                                ipv6_src='2000::1',
                                ipv6_hlim=64)
        exp_pkt = simple_tcpv6_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99aa',
                                ipv6_src='2000::1',
                                ipv6_hlim=63)

        ll_pkt = simple_tcpv6_packet( eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ipv6_dst='FE80::1:100',
                                ipv6_src='5000::1',
                                ipv6_hlim=64)

        ll_nhop_pkt = simple_tcpv6_packet( eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ipv6_dst='1234:5678:9abc::5555:5',
                                ipv6_src='5000::1',
                                ipv6_hlim=64)
        exp_ll_nhop_pkt = simple_tcpv6_packet(
                                eth_dst='00:11:22:55:55:00',
                                eth_src=router_mac,
                                ipv6_dst='1234:5678:9abc::5555:5',
                                ipv6_src='5000::1',
                                ipv6_hlim=63)
        try:
            #  non link-local host route prog with neighbor --> pkt to port1
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])

            #  link-local host route not prog with neighbor --> no pkt sent out
            send_packet(self, switch_ports[1], str(ll_pkt))
            verify_no_other_packets(self, timeout=1)

            #  v6 route with nhop [pointing to link-local-ip] --> pkt to port2
            send_packet(self, switch_ports[1], str(ll_nhop_pkt))
            verify_packets(self, exp_ll_nhop_pkt, [switch_ports[1]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask1, rif_id2)
            self.client.sai_thrift_remove_next_hop(link_local_nhop)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, link_local_ip, dmac2)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

def ip6_to_integer(ip6):
    ip6 = socket.inet_pton(socket.AF_INET6, ip6)
    a, b = unpack(">QQ", ip6)
    return (a << 64) | b

def integer_to_ip6(ip6int):
    a = (ip6int >> 64) & ((1 << 64) - 1)
    b = ip6int & ((1 << 64) - 1)
    return socket.inet_ntop(socket.AF_INET6, pack(">QQ", a, b))

@group('l3')
@disabled
class L3IPv6PrefixTest(sai_base_test.ThriftInterfaceDataPlane):
    #Test packet forwarding for all IPv6 prefix lenghs (from 127 to 1)
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[1]
        port2 = port_list[2]
        port3 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        addr_family = SAI_IP_ADDR_FAMILY_IPV6

        #Create neighbor and neighbor subnet
        ip_addr1 = '2000:aaaa::1'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, '2000:aaaa::', 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:fff0', rif_id1)

        dest = '1234:5678:9abc:def0:4422:1133:5577:99aa'
        dest_int = ip6_to_integer(dest)

        try:
            for i in range(128):
                mask_int = ( ( 1 << (128-i) ) - 1 ) << i
                net_int = dest_int & mask_int
                mask = integer_to_ip6(mask_int)
                net = integer_to_ip6(net_int)

                pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                          eth_src='00:22:22:22:22:22',
                                          ipv6_dst=dest,
                                          ipv6_src='2000:bbbb::1',
                                          ipv6_hlim=64)
                exp_pkt = simple_tcpv6_packet(eth_dst='00:11:22:33:44:55',
                                              eth_src=router_mac,
                                              ipv6_dst=dest,
                                              ipv6_src='2000:bbbb::1',
                                              ipv6_hlim=63)

                print "Test packet with dstaddr " + dest + ' sent to ' + net + '/' + str(128-i)
                sai_thrift_create_route(self.client, vr_id, addr_family, net, mask, nhop1)
                send_packet(self,switch_ports[2], str(pkt))
                verify_packets(self, exp_pkt, [1])
                sai_thrift_remove_route(self.client, vr_id, addr_family, net, mask, None)
                mask=""
                send_packet(self,switch_ports[2], str(pkt))
                verify_no_packet(self, exp_pkt, switch_ports[1], timeout=2)
        finally:
            if mask!="":
                sai_thrift_remove_route(self.client, vr_id, addr_family, net, mask, None)
            sai_thrift_remove_route(self.client, vr_id, addr_family, '2000:aaaa::', 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:fff0', None)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3IPv6LpmTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "IPv6 Lpm Test"
        print "Sending packet port 1 -> port 2 (2000::1 -> 3000::1, routing with 3000::0/120 route"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV6
        ip_addr1 = '1234:5678:9abc:def0:0000:0000:0000:0000'
        ip_mask1 = 'ffff:ffff:ffff:ffff:0000:0000:0000:0000'
        ip_mask2 = 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:0000'
        dmac1 = '00:11:22:33:44:55'
        nhop_ip1 = '3000::1'
        nhop_ip1_subnet = '3000::0'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop1)
        sai_thrift_create_route(self.client, vr_id, addr_family, nhop_ip1_subnet, ip_mask2, rif_id1)

        # send the test packet(s)
        pkt = simple_tcpv6_packet( eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99aa',
                                ipv6_src='2000::1',
                                ipv6_hlim=64)
        exp_pkt = simple_tcpv6_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99aa',
                                ipv6_src='2000::1',
                                ipv6_hlim=63)
        try:
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, nhop_ip1_subnet, ip_mask2, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
@group('ecmp')
@group('dynhash')
class L3IPv4EcmpHostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        dmac2 = '00:11:22:33:44:56'

        vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif1 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif2 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        rif3 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif1, ip_addr1, dmac1)
        sai_thrift_create_neighbor(self.client, addr_family, rif2, ip_addr1, dmac2)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif2)

        nhop_group1 = sai_thrift_create_next_hop_group(self.client)

        nhop_gmember1 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop1)
        nhop_gmember2 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop2)

        sai_thrift_create_route(self.client, vr1, addr_family, ip_addr1_subnet, ip_mask1, nhop_group1)
        #sai_thrift_create_route(self.client, vr1, addr_family, ip_addr1_subnet, ip_mask1, rif2)

        # send the test packet(s)
        try:
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=106,
                                ip_ttl=64)

            exp_pkt1 = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=106,
                                #ip_tos=3,
                                ip_ttl=63)
            exp_pkt2 = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:56',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=106,
                                #ip_tos=3,
                                ip_ttl=63)

            send_packet(self,switch_ports[2], str(pkt))
            verify_any_packet_any_port(self, [exp_pkt1, exp_pkt2], [switch_ports[0],switch_ports[1]] )

            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.100.3',
                                    ip_id=106,
                                    ip_ttl=64)

            exp_pkt1 = simple_tcp_packet(
                                    eth_dst='00:11:22:33:44:55',
                                    eth_src=router_mac,
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.100.3',
                                    ip_id=106,
                                    #ip_tos=3,
                                    ip_ttl=63)
            exp_pkt2 = simple_tcp_packet(
                                    eth_dst='00:11:22:33:44:56',
                                    eth_src=router_mac,
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.100.3',
                                    ip_id=106,
                                    #ip_tos=3,
                                    ip_ttl=63)

            send_packet(self,switch_ports[2], str(pkt))
            verify_any_packet_any_port(self, [exp_pkt1, exp_pkt2], [switch_ports[0],switch_ports[1]] )
        finally:
            sai_thrift_remove_route(self.client, vr1, addr_family, ip_addr1_subnet, ip_mask1, nhop_group1)
            #sai_thrift_remove_route(self.client, vr1, addr_family, ip_addr1_subnet, ip_mask1, rif2)

            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember1)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember2)

            self.client.sai_thrift_remove_next_hop_group(nhop_group1)

            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)

            sai_thrift_remove_neighbor(self.client, addr_family, rif1, ip_addr1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif2, ip_addr1, dmac2)

            self.client.sai_thrift_remove_router_interface(rif1)
            self.client.sai_thrift_remove_router_interface(rif2)
            self.client.sai_thrift_remove_router_interface(rif3)

            self.client.sai_thrift_remove_virtual_router(vr1)

@group('l3')
@group('ecmp')
class L3IPv6EcmpHostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV6
        ip_addr1 = '5000:1:1:0:0:0:0:1'
        ip_mask1 = 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff'
        dmac1 = '00:11:22:33:44:55'
        dmac2 = '00:11:22:33:44:56'

        vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif1 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif2 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        rif3 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif1, ip_addr1, dmac1)
        sai_thrift_create_neighbor(self.client, addr_family, rif2, ip_addr1, dmac2)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif2)

        nhop_group1 = sai_thrift_create_next_hop_group(self.client)

        nhop_gmember1 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop1)
        nhop_gmember2 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop2)

        sai_thrift_create_route(self.client, vr1, addr_family, ip_addr1, ip_mask1, nhop_group1)

        # send the test packet(s)
        try:
            pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                      eth_src='00:22:22:22:22:22',
                                      ipv6_dst='5000:1:1:0:0:0:0:1',
                                      ipv6_src='2000:1:1:0:0:0:0:1',
                                      tcp_sport=0x1234,
                                      ipv6_hlim=64)

            exp_pkt1 = simple_tcpv6_packet(eth_dst='00:11:22:33:44:55',
                                           eth_src=router_mac,
                                           ipv6_dst='5000:1:1:0:0:0:0:1',
                                           ipv6_src='2000:1:1:0:0:0:0:1',
                                           tcp_sport=0x1234,
                                           ipv6_hlim=63)
            exp_pkt2 = simple_tcpv6_packet(eth_dst='00:11:22:33:44:56',
                                           eth_src=router_mac,
                                           ipv6_dst='5000:1:1:0:0:0:0:1',
                                           ipv6_src='2000:1:1:0:0:0:0:1',
                                           tcp_sport=0x1234,
                                           ipv6_hlim=63)

            send_packet(self,switch_ports[2], str(pkt))
            verify_any_packet_any_port(self, [exp_pkt1, exp_pkt2], [switch_ports[0],switch_ports[1]] )

            pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                      eth_src='00:22:22:22:22:45',
                                      ipv6_dst='5000:1:1:0:0:0:0:1',
                                      ipv6_src='2000:1:1:0:0:0:0:1',
                                      tcp_sport=0x1248,
                                      ipv6_hlim=64)

            exp_pkt1 = simple_tcpv6_packet(eth_dst='00:11:22:33:44:55',
                                           eth_src=router_mac,
                                           ipv6_dst='5000:1:1:0:0:0:0:1',
                                           ipv6_src='2000:1:1:0:0:0:0:1',
                                           tcp_sport=0x1248,
                                           ipv6_hlim=63)
            exp_pkt2 = simple_tcpv6_packet(eth_dst='00:11:22:33:44:56',
                                           eth_src=router_mac,
                                           ipv6_dst='5000:1:1:0:0:0:0:1',
                                           ipv6_src='2000:1:1:0:0:0:0:1',
                                           tcp_sport=0x1248,
                                           ipv6_hlim=63)

            send_packet(self,switch_ports[2], str(pkt))
            verify_any_packet_any_port(self, [exp_pkt1, exp_pkt2], [switch_ports[0], switch_ports[1]])
        finally:
            sai_thrift_remove_route(self.client, vr1, addr_family, ip_addr1, ip_mask1, nhop_group1)

            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember1)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember2)

            self.client.sai_thrift_remove_next_hop_group(nhop_group1)

            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)

            sai_thrift_remove_neighbor(self.client, addr_family, rif1, ip_addr1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif2, ip_addr1, dmac2)

            self.client.sai_thrift_remove_router_interface(rif1)
            self.client.sai_thrift_remove_router_interface(rif2)
            self.client.sai_thrift_remove_router_interface(rif3)

            self.client.sai_thrift_remove_virtual_router(vr1)

@group('l3')
@group('ecmp')
class L3IPv4EcmpLpmTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 3 -> port [0,1,2] (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.0.0'
        ip_mask1 = '255.255.0.0'
        ip_mask2 = '255.255.255.0'
        nhop_ip1 = '11.11.11.11'
        nhop_ip1_subnet = '11.11.11.0'
        nhop_ip2 = '22.22.22.22'
        nhop_ip2_subnet = '22.22.22.0'
        nhop_ip3 = '33.33.33.33'
        nhop_ip3_subnet = '33.33.33.0'
        dmac1 = '00:11:22:33:44:55'
        dmac2 = '00:11:22:33:44:56'
        dmac3 = '00:11:22:33:44:57'

        vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif1 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif2 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        rif3 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)
        rif4 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port4, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif1, nhop_ip1, dmac1)
        sai_thrift_create_neighbor(self.client, addr_family, rif2, nhop_ip2, dmac2)
        sai_thrift_create_neighbor(self.client, addr_family, rif3, nhop_ip3, dmac3)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip2, rif2)
        nhop3 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip3, rif3)

        nhop_group1 = sai_thrift_create_next_hop_group(self.client)

        nhop_gmember1 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop1)
        nhop_gmember2 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop2)
        nhop_gmember3 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop3)

        sai_thrift_create_route(self.client, vr1, addr_family, ip_addr1, ip_mask1, nhop_group1)
        sai_thrift_create_route(self.client, vr1, addr_family, nhop_ip1_subnet, ip_mask2, rif1)
        sai_thrift_create_route(self.client, vr1, addr_family, nhop_ip2_subnet, ip_mask2, rif2)
        sai_thrift_create_route(self.client, vr1, addr_family, nhop_ip3_subnet, ip_mask2, rif3)

        # send the test packet(s)
        try:
            count = [0, 0, 0]
            dst_ip = int(socket.inet_aton('10.10.10.1').encode('hex'),16)
            max_itrs = 200
            src_mac_start = '00:22:22:22:22:'
            for i in range(0, max_itrs):
                dst_ip_addr = socket.inet_ntoa(hex(dst_ip)[2:].zfill(8).decode('hex'))
                src_mac = src_mac_start + str(i%99).zfill(2)
                pkt = simple_tcp_packet(eth_dst=router_mac,
                                        eth_src=src_mac,
                                        ip_dst=dst_ip_addr,
                                        ip_src='192.168.8.1',
                                        ip_id=106,
                                        ip_ttl=64)
                exp_pkt1 = simple_tcp_packet(eth_dst='00:11:22:33:44:55',
                                             eth_src=router_mac,
                                             ip_dst=dst_ip_addr,
                                             ip_src='192.168.8.1',
                                             ip_id=106,
                                             ip_ttl=63)
                exp_pkt2 = simple_tcp_packet(eth_dst='00:11:22:33:44:56',
                                             eth_src=router_mac,
                                             ip_dst=dst_ip_addr,
                                             ip_src='192.168.8.1',
                                             ip_id=106,
                                             ip_ttl=63)
                exp_pkt3 = simple_tcp_packet(eth_dst='00:11:22:33:44:57',
                                             eth_src=router_mac,
                                             ip_dst=dst_ip_addr,
                                             ip_src='192.168.8.1',
                                             ip_id=106,
                                             ip_ttl=63)

                send_packet(self, switch_ports[3], str(pkt))
                rcv_idx = verify_any_packet_any_port(self,
                                                     [exp_pkt1, exp_pkt2, exp_pkt3],
                                                     [switch_ports[0], switch_ports[1],switch_ports[2]])
                count[rcv_idx] += 1
                dst_ip += 1

            for i in range(0, 3):
                self.assertTrue((count[i] >= ((max_itrs / 3) * 0.8)),
                                "Not all paths are equally balanced, %s" % count)
        finally:
            sai_thrift_remove_route(self.client, vr1, addr_family, ip_addr1, ip_mask1, nhop_group1)
            sai_thrift_remove_route(self.client, vr1, addr_family, nhop_ip1_subnet, ip_mask2, rif1)
            sai_thrift_remove_route(self.client, vr1, addr_family, nhop_ip2_subnet, ip_mask2, rif2)
            sai_thrift_remove_route(self.client, vr1, addr_family, nhop_ip3_subnet, ip_mask2, rif3)

            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember1)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember2)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember3)

            self.client.sai_thrift_remove_next_hop_group(nhop_group1)

            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            self.client.sai_thrift_remove_next_hop(nhop3)

            sai_thrift_remove_neighbor(self.client, addr_family, rif1, nhop_ip1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif2, nhop_ip2, dmac2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif3, nhop_ip3, dmac3)

            self.client.sai_thrift_remove_router_interface(rif1)
            self.client.sai_thrift_remove_router_interface(rif2)
            self.client.sai_thrift_remove_router_interface(rif3)
            self.client.sai_thrift_remove_router_interface(rif4)

            self.client.sai_thrift_remove_virtual_router(vr1)

@disabled
@group('l3')
@group('ecmp')
class L3IPv6EcmpLpmTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV6
        ip_addr1 = '6000:1:1:0:0:0:0:0'
        ip_mask1 = 'ffff:ffff:ffff:ffff:0:0:0:0'
        nhop_ip1 = '2000:1:1:0:0:0:0:1'
        nhop_ip2 = '3000:1:1:0:0:0:0:1'
        nhop_ip3 = '4000:1:1:0:0:0:0:1'
        dmac1 = '00:11:22:33:44:55'
        dmac2 = '00:11:22:33:44:56'
        dmac3 = '00:11:22:33:44:57'

        vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif1 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        rif2 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        rif3 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)
        rif4 = sai_thrift_create_router_interface(self.client, vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port4, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif1, nhop_ip1, dmac1)
        sai_thrift_create_neighbor(self.client, addr_family, rif2, nhop_ip2, dmac2)
        sai_thrift_create_neighbor(self.client, addr_family, rif3, nhop_ip3, dmac3)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip2, rif2)
        nhop3 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip3, rif3)

        nhop_group1 = sai_thrift_create_next_hop_group(self.client)

        nhop_gmember1 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop1)
        nhop_gmember2 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop2)
        nhop_gmember3 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop3)

        sai_thrift_create_route(self.client, vr1, addr_family, ip_addr1, ip_mask1, nhop_group1)

        # send the test packet(s)
        try:
            count = [0, 0, 0]
            dst_ip = socket.inet_pton(socket.AF_INET6, '6000:1:1:0:0:0:0:1')
            dst_ip_arr = list(dst_ip)
            src_mac_start = '00:22:22:22:22:'
            max_itrs = 200
            sport = 0x1234
            dport = 0x50
            for i in range(0, max_itrs):
                dst_ip_addr = socket.inet_ntop(socket.AF_INET6, dst_ip)
                src_mac = src_mac_start + str(i%99).zfill(2)
                #HACK: sport is a hack for hashing since the ecmp hash does not
                #include ipv6 sa and da.
                pkt = simple_tcpv6_packet(
                        eth_dst=router_mac,
                        eth_src=src_mac,
                        ipv6_dst=dst_ip_addr,
                        ipv6_src='1001:1:1:0:0:0:0:2',
                        tcp_sport=sport,
                        tcp_dport=dport,
                        ipv6_hlim=64)
                exp_pkt1 = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:55',
                        eth_src=router_mac,
                        ipv6_dst=dst_ip_addr,
                        ipv6_src='1001:1:1:0:0:0:0:2',
                        tcp_sport=sport,
                        tcp_dport=dport,
                        ipv6_hlim=63)
                exp_pkt2 = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:56',
                        eth_src=router_mac,
                        ipv6_dst=dst_ip_addr,
                        ipv6_src='1001:1:1:0:0:0:0:2',
                        tcp_sport=sport,
                        tcp_dport=dport,
                        ipv6_hlim=63)
                exp_pkt3 = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:57',
                        eth_src=router_mac,
                        ipv6_dst=dst_ip_addr,
                        ipv6_src='1001:1:1:0:0:0:0:2',
                        tcp_sport=sport,
                        tcp_dport=dport,
                        ipv6_hlim=63)
                exp_pkt4 = simple_tcpv6_packet(
                        eth_dst='00:11:22:33:44:58',
                        eth_src=router_mac,
                        ipv6_dst=dst_ip_addr,
                        ipv6_src='1001:1:1:0:0:0:0:2',
                        tcp_sport=sport,
                        tcp_dport=dport,
                        ipv6_hlim=63)

                send_packet(self,switch_ports[3], str(pkt))
                rcv_idx = verify_any_packet_any_port(self,
                                                     [exp_pkt1, exp_pkt2, exp_pkt3],
                                                    [switch_ports[0], switch_ports[1], switch_ports[2]])
                count[rcv_idx] += 1
                dst_ip_arr[15] = chr(ord(dst_ip_arr[15]) + 1)
                dst_ip = ''.join(dst_ip_arr)
                sport += 15
                dport += 20

            print "Count = %s" % str(count)
            for i in range(0, 3):
                self.assertTrue((count[i] >= ((max_itrs / 3) * 0.75)),
                                "Not all paths are equally balanced")
        finally:
            sai_thrift_remove_route(self.client, vr1, addr_family, ip_addr1, ip_mask1, nhop_group1)

            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember1)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember2)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember3)

            self.client.sai_thrift_remove_next_hop_group(nhop_group1)

            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            self.client.sai_thrift_remove_next_hop(nhop3)

            sai_thrift_remove_neighbor(self.client, addr_family, rif1, nhop_ip1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif2, nhop_ip2, dmac2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif3, nhop_ip3, dmac3)

            self.client.sai_thrift_remove_router_interface(rif1)
            self.client.sai_thrift_remove_router_interface(rif2)
            self.client.sai_thrift_remove_router_interface(rif3)
            self.client.sai_thrift_remove_router_interface(rif4)

            self.client.sai_thrift_remove_virtual_router(vr1)

@group('l3')
@group('lag')
@group('dynhash')
class L3IPv4LagTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        lag_id1 = self.client.sai_thrift_create_lag([])

        lag_member_id1 = sai_thrift_create_lag_member(self.client, lag_id1, port1)
        lag_member_id2 = sai_thrift_create_lag_member(self.client, lag_id1, port2)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, lag_id1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        # send the test packet(s)
        try:
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.0.1',
                                    ip_id=110,
                                    ip_ttl=64)

            exp_pkt = simple_tcp_packet(
                                    eth_dst='00:11:22:33:44:55',
                                    eth_src=router_mac,
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.0.1',
                                    ip_id=110,
                                    ip_ttl=63)
            send_packet(self,switch_ports[2], str(pkt))
            verify_packets_any(self, exp_pkt, [switch_ports[0], switch_ports[1]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            sai_thrift_remove_lag_member(self.client, lag_member_id1)
            sai_thrift_remove_lag_member(self.client, lag_member_id2)
            self.client.sai_thrift_remove_lag(lag_id1)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
@group('lag')
class L3IPv6LagTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        lag_id1 = self.client.sai_thrift_create_lag([])
        lag_member_id1 = sai_thrift_create_lag_member(self.client, lag_id1, port1)
        lag_member_id2 = sai_thrift_create_lag_member(self.client, lag_id1, port2)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, lag_id1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV6
        ip_addr1 = '4001::1'
        ip_addr1_subnet = '4001::0'
        ip_mask1 = 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        # send the test packet(s)
        try:
            pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ipv6_dst='4001::1',
                                    ipv6_src='5001::1',
                                    ipv6_hlim=64)

            exp_pkt = simple_tcpv6_packet(
                                    eth_dst='00:11:22:33:44:55',
                                    eth_src=router_mac,
                                    ipv6_dst='4001::1',
                                    ipv6_src='5001::1',
                                    ipv6_hlim=63)
            send_packet(self,switch_ports[2], str(pkt))
            verify_packets_any(self, exp_pkt, [switch_ports[0], switch_ports[1]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)

            sai_thrift_remove_lag_member(self.client, lag_member_id1)
            sai_thrift_remove_lag_member(self.client, lag_member_id2)
            self.client.sai_thrift_remove_lag(lag_id1)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
@group('ecmp')
@group('lag')
class L3EcmpLagTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        switch_init(self.client)
        if len(port_list) < 7:
            assert False, "skip this test as it requires 7 ports"

        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        port5 = port_list[4]
        port6 = port_list[5]
        port7 = port_list[6]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.0.0'
        ip_mask1 = '255.255.0.0'
        nhop_ip1 = '11.11.11.11'
        nhop_ip2 = '22.22.22.22'
        nhop_ip3 = '33.33.33.33'
        dmac1 = '00:11:22:33:44:55'
        dmac2 = '00:11:22:33:44:56'
        dmac3 = '00:11:22:33:44:57'

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        lag_id1 = self.client.sai_thrift_create_lag([])
        lag_id2 = self.client.sai_thrift_create_lag([])

        lag_member_id1 = sai_thrift_create_lag_member(self.client, lag_id1, port1)
        lag_member_id2 = sai_thrift_create_lag_member(self.client, lag_id1, port2)
        lag_member_id3 = sai_thrift_create_lag_member(self.client, lag_id1, port3)
        lag_member_id4 = sai_thrift_create_lag_member(self.client, lag_id2, port4)
        lag_member_id5 = sai_thrift_create_lag_member(self.client, lag_id2, port5)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, lag_id1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, lag_id2, 0, v4_enabled, v6_enabled, mac)
        rif_id3 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port6, 0, v4_enabled, v6_enabled, mac)
        rif_id4 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port7, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, nhop_ip2, dmac2)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id3, nhop_ip3, dmac3)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif_id1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip2, rif_id2)
        nhop3 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip3, rif_id3)

        nhop_group1 = sai_thrift_create_next_hop_group(self.client)

        nhop_gmember1 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop1)
        nhop_gmember2 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop2)
        nhop_gmember3 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop3)

        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop_group1)

        try:
            count = [0, 0, 0, 0, 0, 0]
            dst_ip = int(socket.inet_aton('10.10.10.1').encode('hex'), 16)
            src_mac_start = '00:22:22:22:{0}:{1}'
            max_itrs = 500
            for i in range(0, max_itrs):
                dst_ip_addr = socket.inet_ntoa(hex(dst_ip)[2:].zfill(8).decode('hex'))
                src_mac = src_mac_start.format(str(i).zfill(4)[:2], str(i).zfill(4)[2:])
                pkt = simple_tcp_packet(eth_dst=router_mac,
                        eth_src=src_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        ip_ttl=64)

                exp_pkt1 = simple_tcp_packet(eth_dst='00:11:22:33:44:55',
                        eth_src=router_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        ip_ttl=63)
                exp_pkt2 = simple_tcp_packet(eth_dst='00:11:22:33:44:56',
                        eth_src=router_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        ip_ttl=63)
                exp_pkt3 = simple_tcp_packet(eth_dst='00:11:22:33:44:57',
                        eth_src=router_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        ip_ttl=63)

                send_packet(self, switch_ports[6], str(pkt))
                ports_to_verify = switch_ports[0:6]
                rcv_idx = verify_any_packet_any_port(self,
                                                     [exp_pkt1, exp_pkt2, exp_pkt3],
                                                      ports_to_verify )
                count[rcv_idx] += 1
                dst_ip += 1

            print count
            ecmp_count = [count[0]+count[1]+count[2], count[3]+count[4], count[5]]
            for i in range(0, 3):
                self.assertTrue((ecmp_count[i] >= ((max_itrs / 3) * 0.75)),
                                "Ecmp paths are not equally balanced")
            for i in range(0, 3):
                self.assertTrue((count[i] >= ((max_itrs / 9) * 0.75)),
                                "Lag path1 is not equally balanced")
            for i in range(3, 5):
                self.assertTrue((count[i] >= ((max_itrs / 6) * 0.75)),
                                "Lag path2 is not equally balanced")
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop_group1)

            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember1)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember2)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember3)

            self.client.sai_thrift_remove_next_hop_group(nhop_group1)

            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            self.client.sai_thrift_remove_next_hop(nhop3)

            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, nhop_ip2, dmac2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id3, nhop_ip3, dmac3)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_router_interface(rif_id3)
            self.client.sai_thrift_remove_router_interface(rif_id4)

            sai_thrift_remove_lag_member(self.client, lag_member_id1)
            sai_thrift_remove_lag_member(self.client, lag_member_id2)
            sai_thrift_remove_lag_member(self.client, lag_member_id3)
            sai_thrift_remove_lag_member(self.client, lag_member_id4)
            sai_thrift_remove_lag_member(self.client, lag_member_id5)

            self.client.sai_thrift_remove_lag(lag_id1)
            self.client.sai_thrift_remove_lag(lag_id2)

            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
@group('ecmp')
@group('lag')
class L3EcmpLagTestMini(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac = ''

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.0.0'
        ip_mask1 = '255.255.0.0'
        ip_mask2 = '255.255.255.0'
        nhop_ip1 = '11.11.11.11'
        nhop_ip1_subnet = '11.11.11.0'
        nhop_ip2 = '22.22.22.22'
        nhop_ip2_subnet = '22.22.22.0'
        dmac1 = '00:11:22:33:44:55'
        dmac2 = '00:11:22:33:44:56'

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        lag_id1 = self.client.sai_thrift_create_lag([])

        lag_member11 = sai_thrift_create_lag_member(self.client, lag_id1, port1)
        lag_member12 = sai_thrift_create_lag_member(self.client, lag_id1, port2)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, lag_id1, 0, v4_enabled, v6_enabled, mac)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)
        rif_id3 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port4, 0, v4_enabled, v6_enabled, mac)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, nhop_ip2, dmac2)

        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif_id1)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip2, rif_id2)

        nhop_group1 = sai_thrift_create_next_hop_group(self.client)

        nhop_gmember1 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop1)
        nhop_gmember2 = sai_thrift_create_next_hop_group_member(self.client, nhop_group1, nhop2)

        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop_group1)
        sai_thrift_create_route(self.client, vr_id, addr_family, nhop_ip1_subnet, ip_mask2, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, nhop_ip2_subnet, ip_mask2, rif_id2)

        try:
            count = [0, 0, 0]
            dst_ip = int(socket.inet_aton('10.10.10.1').encode('hex'), 16)
            src_mac_start = '00:22:22:22:23:'
            max_itrs = 500
            dport = 0x50
            for i in range(0, max_itrs):
                dst_ip_addr = socket.inet_ntoa(hex(dst_ip)[2:].zfill(8).decode('hex'))
                src_mac = src_mac_start + str(i%99).zfill(2)
                pkt = simple_tcp_packet(eth_dst=router_mac,
                        eth_src=src_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        tcp_dport=dport,
                        ip_ttl=64)

                exp_pkt1 = simple_tcp_packet(eth_dst='00:11:22:33:44:55',
                        eth_src=router_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        tcp_dport=dport,
                        ip_ttl=63)
                exp_pkt2 = simple_tcp_packet(eth_dst='00:11:22:33:44:56',
                        eth_src=router_mac,
                        ip_dst=dst_ip_addr,
                        ip_src='192.168.8.1',
                        ip_id=106,
                        tcp_dport=dport,
                        ip_ttl=63)

                send_packet(self,switch_ports[3], str(pkt))
                rcv_idx = verify_any_packet_any_port(self,
                              [exp_pkt1, exp_pkt2],
                              [switch_ports[0], switch_ports[1], switch_ports[2]])
                count[rcv_idx] += 1
                dst_ip += 1
                dport += 20

            print count
            ecmp_count = [count[0] + count[1], count[2]]
            for i in range(0, 2):
                self.assertTrue((ecmp_count[i] >= ((max_itrs / 2) * 0.75)),
                        "Ecmp paths are not equally balanced")
            for i in range(0, 2):
                self.assertTrue((count[i] >= ((max_itrs / 4) * 0.75)),
                        "Lag path1 is not equally balanced")
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop_group1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, nhop_ip1_subnet, ip_mask2, rif_id1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, nhop_ip2_subnet, ip_mask2, rif_id2)

            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember1)
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember2)

            self.client.sai_thrift_remove_next_hop_group(nhop_group1)

            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)

            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, nhop_ip2, dmac2)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_router_interface(rif_id3)

            sai_thrift_remove_lag_member(self.client, lag_member11)
            sai_thrift_remove_lag_member(self.client, lag_member12)

            self.client.sai_thrift_remove_lag(lag_id1)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
class L3VIIPv4HostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        vlan_id = 10
        mac_action = SAI_PACKET_ACTION_FORWARD

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:0a:00:00:00:01'
        ip_addr2 = '11.11.11.1'
        ip_addr2_subnet = '11.11.11.0'
        ip_mask2 = '255.255.255.0'
        dmac2 = '00:0b:00:00:00:01'
        mac1 = ''
        mac2 = ''

        vlan_oid = sai_thrift_create_vlan(self.client, vlan_id)
        vlan_member1 = sai_thrift_create_vlan_member(self.client, vlan_oid, port1, SAI_VLAN_TAGGING_MODE_UNTAGGED)

        attr_value = sai_thrift_attribute_value_t(u16=vlan_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port1, attr)

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan_oid, v4_enabled, v6_enabled, mac1)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac2)

        sai_thrift_create_fdb(self.client, vlan_oid, dmac1, port1, mac_action)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)

        try:
            # send the test packet(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:0a:00:00:00:01',
                                ip_dst='11.11.11.1',
                                ip_src='10.10.10.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:0b:00:00:00:01',
                                eth_src=router_mac,
                                ip_dst='11.11.11.1',
                                ip_src='10.10.10.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, 0, str(pkt))
            verify_packets(self, exp_pkt, [1])

            # send the test packet(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:0b:00:00:00:01',
                                ip_dst='10.10.10.1',
                                ip_src='11.11.11.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:0a:00:00:00:01',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='11.11.11.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)
            self.client.sai_thrift_remove_next_hop(nhop1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)
            sai_thrift_delete_fdb(self.client, vlan_oid, dmac1, port1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_vlan_member(vlan_member1)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port1, attr)

            self.client.sai_thrift_remove_vlan(vlan_oid)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('l3')
@disabled
class L3VI2VIIPv4HostTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        mac_action = SAI_PACKET_ACTION_FORWARD
        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        vlan100_id = 100
        vlan200_id = 200
        ip_addr2 = '11.11.11.1'
        ip_addr2_subnet = '11.11.11.0'
        ip_mask2 = '255.255.255.0'
        dmac2 = '00:0b:00:00:00:01'
        ip_addr3 = '12.12.12.1'
        ip_addr3_subnet = '12.12.12.0'
        ip_mask3 = '255.255.255.0'
        dmac3 = '00:0c:00:00:00:01'
        mac1 = ''
        mac2 = ''

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        vlan100 = sai_thrift_create_vlan(self.client, vlan100_id)
        vlan200 = sai_thrift_create_vlan(self.client, vlan200_id)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan100, v4_enabled, v6_enabled, mac1)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan200, v4_enabled, v6_enabled, mac2)

        lag1 = sai_thrift_create_lag(self.client, [])
        lag3 = sai_thrift_create_lag(self.client, [])

        lag1_member = sai_thrift_create_lag_member(self.client, lag1, port1)
        lag3_member = sai_thrift_create_lag_member(self.client, lag3, port2)

        vlan100_member_nt = sai_thrift_create_vlan_member(self.client, vlan100, lag1, SAI_VLAN_TAGGING_MODE_UNTAGGED)
        vlan100_member_t = sai_thrift_create_vlan_member(self.client, vlan100, lag3, SAI_VLAN_TAGGING_MODE_TAGGED)

        attr_value1 = sai_thrift_attribute_value_t(u16=vlan100_id)
        attr1 = sai_thrift_attribute_t(id=SAI_LAG_ATTR_PORT_VLAN_ID, value=attr_value1)
        self.client.sai_thrift_set_lag_attribute(lag1, attr1)

        vlan200_member_t = sai_thrift_create_vlan_member(self.client, vlan200, lag1, SAI_VLAN_TAGGING_MODE_TAGGED)
        vlan200_member_nt = sai_thrift_create_vlan_member(self.client, vlan200, lag3, SAI_VLAN_TAGGING_MODE_UNTAGGED)

        attr_value1 = sai_thrift_attribute_value_t(u16=vlan200_id)
        attr1 = sai_thrift_attribute_t(id=SAI_LAG_ATTR_PORT_VLAN_ID, value=attr_value1)
        self.client.sai_thrift_set_lag_attribute(lag3, attr1)

        sai_thrift_create_fdb(self.client, vlan200, dmac2, lag3, mac_action)
        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr3, dmac3)
        nhop3 = sai_thrift_create_nhop(self.client, addr_family, ip_addr3, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr3_subnet, ip_mask3, rif_id2)
        sai_thrift_create_fdb(self.client, vlan200, dmac3, lag1, mac_action)

        try:
            # send the test packet(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:0a:00:00:00:01',
                                ip_dst='11.11.11.1',
                                ip_src='10.10.10.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:0b:00:00:00:01',
                                eth_src=router_mac,
                                ip_dst='11.11.11.1',
                                ip_src='10.10.10.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, 0, str(pkt))
            verify_packets(self, exp_pkt, [1])

            # send the tagged test packet and expect it untagged
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:0a:00:00:00:01',
                                ip_dst='11.11.11.1',
                                ip_src='10.10.10.1',
                                dl_vlan_enable=True,
                                vlan_vid=vlan100_id,
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:0b:00:00:00:01',
                                eth_src=router_mac,
                                ip_dst='11.11.11.1',
                                ip_src='10.10.10.1',
                                ip_id=105,
                                ip_ttl=63,
                                pktlen=96)
            send_packet(self, 0, str(pkt))
            verify_packets(self, exp_pkt, [1])

            # send the tagged test packet and expect it as tagged
            # with other vlan
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:0b:00:00:00:01',
                                ip_dst='12.12.12.1',
                                ip_src='11.11.11.1',
                                dl_vlan_enable=True,
                                vlan_vid=vlan100_id,
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:0c:00:00:00:01',
                                eth_src=router_mac,
                                ip_dst='12.12.12.1',
                                ip_src='11.11.11.1',
                                dl_vlan_enable=True,
                                vlan_vid=vlan200_id,
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])

        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr3_subnet, ip_mask3, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop2)
            self.client.sai_thrift_remove_next_hop(nhop3)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr3, dmac3)
            #remove the entry automatically learned first
            sai_thrift_flush_fdb_by_vlan(self.client, vlan100)
            sai_thrift_delete_fdb(self.client, vlan200, dmac2, lag3)
            sai_thrift_delete_fdb(self.client, vlan200, dmac3, lag1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_virtual_router(vr_id)

            self.client.sai_thrift_remove_vlan_member(vlan100_member_nt)
            self.client.sai_thrift_remove_vlan_member(vlan100_member_t)
            self.client.sai_thrift_remove_vlan_member(vlan200_member_nt)
            self.client.sai_thrift_remove_vlan_member(vlan200_member_t)
            attr_value1 = sai_thrift_attribute_value_t(u16=1)
            attr1 = sai_thrift_attribute_t(id=SAI_LAG_ATTR_PORT_VLAN_ID, value=attr_value1)
            self.client.sai_thrift_set_port_attribute(lag1, attr1)
            self.client.sai_thrift_set_port_attribute(lag3, attr1)

            self.client.sai_thrift_remove_vlan(vlan100)
            self.client.sai_thrift_remove_vlan(vlan200)

            sai_thrift_remove_lag_member(self.client, lag1_member)
            sai_thrift_remove_lag_member(self.client, lag3_member)
            sai_thrift_remove_lag(self.client, lag1)
            sai_thrift_remove_lag(self.client, lag3)

@group('l3')
class L3IPv4MacRewriteTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1

        mac1 = rewrite_mac1
        mac2 = rewrite_mac2

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac1)
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac2)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        nhop_ip1 = '11.11.11.11'
        nhop_ip1_subnet = '11.11.11.0'
        nhop_ip1_mask = '255.255.255.0'
        ip_mask1 = '255.255.255.255'
        ip_addr1 = '10.10.10.1'
        dmac1 = '00:11:22:33:44:55'

        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, nhop_ip1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop1)
        sai_thrift_create_route(self.client, vr_id, addr_family, nhop_ip1_subnet, nhop_ip1_mask, rif_id1)

        # send the test packet(s)
        pkt = simple_tcp_packet(eth_dst=rewrite_mac2,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=rewrite_mac1,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
        try:
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1, ip_mask1, nhop1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, nhop_ip1_subnet, nhop_ip1_mask, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, nhop_ip1, dmac1)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_virtual_router(vr_id)


@group('l3')
class L3VlanNeighborMacUpdateTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        """
        For sai server for testing learning inside vlan and fwd packet to vlan through l3
        Steps
        1. Create VLAN
        2. Create two VLAN members
        3. Set port VLAN IDs
        4. Create virtual router
        5. Create router interface for VLAN and an extra port 3
        6. Set SAI PORT LEARN MODE HW
        7. Send packet from one port of the VLAN to the DUT to update the FDB entry
        8. Create neighbor and route
        9. Send L3 packet from port to the VLAN with the destination IP and verify that only the targeted port receives the packet and the MAC in the packet is updated 
        10. clean up.
        """

        print
        print "Sending packet port 1 -> switch (for learning purpuse)"
        print "and then sending packet from port 3 -> port 1 (through the router)"
        switch_init(self.client)
        sai_thrift_clear_all_counters(self.client)
        v4_enabled = 1
        v6_enabled = 1
        vlan_id = 10
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        mac_port1 = '00:0a:00:00:00:01'
        ip_port1 = '10.10.10.2'
        mac_port3 = '00:0b:00:00:00:01'
        mac1 = ''
        mac2 = ''

        vlan1 = sai_thrift_create_vlan(self.client, vlan_id)

        vlan_member1 = sai_thrift_create_vlan_member(self.client, vlan1, port1, SAI_VLAN_TAGGING_MODE_TAGGED)
        vlan_member2 = sai_thrift_create_vlan_member(self.client, vlan1, port2, SAI_VLAN_TAGGING_MODE_TAGGED)

        attr_value1 = sai_thrift_attribute_value_t(u16=vlan_id)
        attr1 = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value1)
        self.client.sai_thrift_set_port_attribute(port1, attr1)
        self.client.sai_thrift_set_port_attribute(port2, attr1)

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_vlan_id = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan1, v4_enabled, v6_enabled, mac1)
        rif_port_id = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac2)

        attr_value2 = sai_thrift_attribute_value_t(s32=SAI_BRIDGE_PORT_FDB_LEARNING_MODE_HW)
        attr2 = sai_thrift_attribute_t(id=SAI_BRIDGE_PORT_ATTR_FDB_LEARNING_MODE, value=attr_value2)
        self.client.sai_thrift_set_bridge_port_attribute(sai_thrift_get_bridge_port_by_port(self.client, port1), attr2)
        self.client.sai_thrift_set_bridge_port_attribute(sai_thrift_get_bridge_port_by_port(self.client, port2), attr2)

        sai_thrift_create_neighbor(self.client, addr_family, rif_vlan_id, ip_port1, mac_port1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_vlan_id)

        local_pkt = simple_tcp_packet(eth_dst='00:22:22:22:22:22',
                                eth_src=mac_port1,
                                dl_vlan_enable=True,
                                vlan_vid=vlan_id,
                                ip_dst='10.0.0.1',
                                ip_src=ip_port1,
                                ip_id=102,
                                ip_ttl=64)

        try:
            #sending unkown UC for learning the ports mac and expecting flooding only on the vlan
            send_packet(self, switch_ports[0], str(local_pkt))
            verify_packets(self, local_pkt, [switch_ports[1]])

            #sending L3 packet from port 3 through router to port 1 that update the fdb with is MAC
            L3_pkt = simple_tcp_packet(pktlen=100,
                                       eth_dst=router_mac,
                                       eth_src=mac_port3,
                                       ip_src='11.11.11.1',
                                       ip_dst=ip_port1,
                                       ip_id=105,
                                       ip_ttl=64)
            exp_pkt = simple_tcp_packet(pktlen=104,#additional 4bytes because of the vlan
                                        eth_dst=mac_port1,
                                        eth_src=router_mac,
                                        ip_dst=ip_port1,
                                        ip_src='11.11.11.1',
                                        dl_vlan_enable=True,
                                        vlan_vid=vlan_id,
                                        ip_id=105,
                                        ip_ttl=63)

            send_packet(self,switch_ports[2], str(L3_pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_vlan_id)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_vlan_id, ip_port1, mac_port1)

            self.client.sai_thrift_remove_router_interface(rif_vlan_id)
            self.client.sai_thrift_remove_router_interface(rif_port_id)

            self.client.sai_thrift_remove_vlan_member(vlan_member1)
            self.client.sai_thrift_remove_vlan_member(vlan_member2)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port1, attr)
            self.client.sai_thrift_set_port_attribute(port2, attr)

            self.client.sai_thrift_remove_vlan(vlan1)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@group('lag')
@group('l3')
@disabled
class L3MultipleLagTest(sai_base_test.ThriftInterfaceDataPlane):
    total_lag_port = 16
    v4_enabled = 1
    v6_enabled = 1
    ip_mask = '255.255.255.0'
    addr_family = SAI_IP_ADDR_FAMILY_IPV4
    lag_members = []
    lags = []
    lags_rifs = []
    nhops = []
    neighbors = []
    routes = []
    vr_id = 0
    mac_action = SAI_PACKET_ACTION_FORWARD
    src_port = 0
    mac_pool = ['00:11:22:33:44:50',
               '00:11:23:33:44:51',
               '00:11:24:33:44:52',
               '00:11:25:33:44:53',
               '00:11:26:33:44:54',
               '00:11:27:33:44:55',
               '00:11:28:33:44:56',
               '00:11:29:33:44:57',
               '00:11:30:33:44:58',
               '00:11:31:33:44:59',
               '00:11:32:33:44:60',
               '00:11:33:33:44:61',
               '00:11:34:33:44:62',
               '00:11:35:33:44:63',
               '00:11:36:33:44:64',
               '00:11:37:33:44:65',
               '00:11:38:33:44:66']

    def setup_lags(self, num_of_lags, port_list):
        for i in xrange(num_of_lags):
            self.lags.append(self.client.sai_thrift_create_lag([]))
        for i in xrange(self.total_lag_port):
            self.lag_members.append(sai_thrift_create_lag_member(self.client, self.lags[i % num_of_lags], port_list[i]))
        for i in xrange(num_of_lags):
            self.lags_rifs.append(sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, self.lags[i], 0, self.v4_enabled, self.v6_enabled, ''))
        for i in xrange(num_of_lags):
            sai_thrift_create_neighbor(self.client, self.addr_family, self.lags_rifs[i], "10.10.%s.1" % str(i+1), self.mac_pool[i])
            self.nhops.append(sai_thrift_create_nhop(self.client, self.addr_family, "10.10.%s.1" % str(i+1), self.lags_rifs[i]))
            sai_thrift_create_route(self.client, self.vr_id, self.addr_family, "10.10.%s.0" % str(i+1), self.ip_mask, self.lags_rifs[i])

    def teardown_lags(self, num_of_lags, port_list):
        if (num_of_lags == 0 ): return
        for i in xrange(num_of_lags):
            sai_thrift_remove_route(self.client, self.vr_id, self.addr_family, "10.10.%s.0" % str(i+1), self.ip_mask, self.lags_rifs[i])
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.lags_rifs[i], "10.10.%s.1" % str(i+1), self.mac_pool[i])
        for nhop in self.nhops:
            self.client.sai_thrift_remove_next_hop(nhop)
        del self.nhops[:]
        for rif in self.lags_rifs:
            self.client.sai_thrift_remove_router_interface(rif)
        del self.lags_rifs[:]
        for lag_member in self.lag_members:
            sai_thrift_remove_lag_member(self.client, lag_member)
        del self.lag_members[:]
        for lag in self.lags:
            self.client.sai_thrift_remove_lag(lag)
        del self.lags[:]

    def send_and_verify_packets(self, num_of_lags, port_list):
        exp_pkts = [0]*self.total_lag_port
        pkt_counter = [0] * self.total_lag_port
        destanation_ports = range(self.total_lag_port)
        sport = 0x1234
        dport = 0x50
        src_mac_start = '00:22:22:22:{0}:{1}'
        NUM_OF_PKT_TO_EACH_PORT = 254
        NUM_OF_PKTS_TO_SEND = NUM_OF_PKT_TO_EACH_PORT * self.total_lag_port
        for i in xrange(NUM_OF_PKTS_TO_SEND):
                ip_src = '10.0.' + str(i % 255) + '.' + str(i % 255)
                ip_dst = '10.10.' + str((i % num_of_lags) + 1) + '.1'
                src_mac = src_mac_start.format(str(i).zfill(4)[:2], str(i).zfill(4)[2:])
                pkt = simple_tcp_packet(eth_dst=router_mac,
                                        eth_src=src_mac,
                                        ip_src=ip_src,
                                        ip_dst=ip_dst,
                                        ip_id=i,
                                        tcp_sport=sport,
                                        tcp_dport=dport,
                                        ip_ttl=64)
                exp_pkt = simple_tcp_packet(eth_dst=self.mac_pool[i % num_of_lags],
                                            eth_src=router_mac,
                                            ip_src=ip_src,
                                            ip_dst=ip_dst,
                                            ip_id=i,
                                            tcp_sport=sport,
                                            tcp_dport=dport,
                                            ip_ttl=63)

                send_packet(self, self.total_lag_port, str(pkt))
                (match_index,rcv_pkt) = verify_packet_any_port(self,exp_pkt,destanation_ports)
                logging.debug("found expected packet from port %d" % destanation_ports[match_index])
                pkt_counter[match_index] += 1
                sport = random.randint(0,0xffff)
                dport = random.randint(0,0xffff)

        #final uniform distribution check
        for stat_port in xrange(self.total_lag_port):
            logging.debug( "PORT #"+str(hex(port_list[stat_port]))+":")
            logging.debug(str(pkt_counter[stat_port]))
            self.assertTrue((pkt_counter[stat_port] >= ((NUM_OF_PKT_TO_EACH_PORT ) * 0.8)),
                    "Not all paths are equally balanced, %s" % pkt_counter[stat_port])
            self.assertTrue((pkt_counter[stat_port] <= ((NUM_OF_PKT_TO_EACH_PORT ) * 1.2)),
                    "Not all paths are equally balanced, %s" % pkt_counter[stat_port])

    def runTest(self):
        """
        For sai server, testing different lags with router
        ---- Test for 17 ports minimun ----
        Steps
        1. Create virtual router
        2. Reserve port 16 for sending packets
        3. Create router interfaces 1-for all the lags, 2-for the source port 
        4. Create sixteen LAGs with each hash one member
        5. Config neighbors and routes 
        6. Send packet and check for arrivals balanced traffic
        7. Repeat steps 3-6 with 8 lags with each has 2 members, 4 lags with 4 members, 2 lags with 8 members and 1 lag with 16 members
        8. clean up.
        """

        print
        print "L3MultipleLagTest"
        #general configuration 
        random.seed(1)
        switch_init(self.client)
        if (len(port_list) < (self.total_lag_port + 1) ) : 
            assert False, "skip this test as it requires 17 ports"

        self.src_port = port_list[self.total_lag_port]
        self.vr_id = sai_thrift_create_virtual_router(self.client, self.v4_enabled, self.v6_enabled)
        rif_port_id = sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, self.src_port, 0, self.v4_enabled, self.v6_enabled, '')
        num_of_lags = self.total_lag_port

        try:
            while (num_of_lags > 0):
                print "Testing with " + str(num_of_lags) + " lags."
                self.setup_lags(num_of_lags,port_list)
                self.send_and_verify_packets(num_of_lags,port_list)
                self.teardown_lags(num_of_lags,port_list)
                num_of_lags /= 2
        finally:
            #in case of an exception in the send_and_verify_packets
            self.teardown_lags(num_of_lags,port_list)
            self.client.sai_thrift_remove_router_interface(rif_port_id)
            self.client.sai_thrift_remove_virtual_router(self.vr_id)
            print "END OF TEST"

@group('lag')
@group('l3')
@group('not-working')
@disabled
class L3MultipleEcmpLagTest(sai_base_test.ThriftInterfaceDataPlane):
    # ports that will change from rif to lag member
    total_changing_ports = 15
    #the first port that will start as rif, that means that the first iteratio will only have port  #1
    first_changing_port = 2
    total_dst_port = 16
    v4_enabled = 1
    v6_enabled = 1
    ip_mask = '255.255.0.0'
    addr_family = SAI_IP_ADDR_FAMILY_IPV4
    lag_members = []
    nhop_group =  0
    lag = 0
    lag_rif = 0
    port_rifs = []
    neighbors = []
    nhops = []
    nhop_gmembers = []
    routes = []
    vr_id = 0
    mac_action = SAI_PACKET_ACTION_FORWARD
    src_port = 0
    mac_pool = []

    def setup_ecmp_lag_group(self, first_rif_port):
        self.lag = self.client.sai_thrift_create_lag([])
        #adding lag members
        self.lag_members.append(sai_thrift_create_lag_member(self.client, self.lag, port_list[1]))
        for i in range(self.first_changing_port,first_rif_port):
            self.lag_members.append(sai_thrift_create_lag_member(self.client, self.lag, port_list[i]))
        self.lag_rif = sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, self.lag, 0, self.v4_enabled, self.v6_enabled, '')
        sai_thrift_create_neighbor(self.client, self.addr_family, self.lag_rif, "10.10.0.1", self.mac_pool[self.total_changing_ports])
        self.nhops.append(sai_thrift_create_nhop(self.client, self.addr_family, "10.10.0.1" , self.lag_rif))
        sai_thrift_create_route(self.client, self.vr_id,self.addr_family, "10.10.0.1", '255.255.255.0', self.lag_rif)
        for i in range(first_rif_port,self.total_changing_ports):
            self.port_rifs.append(sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port_list[i], 0, self.v4_enabled, self.v6_enabled, ''))
        for i in range(len(self.port_rifs)):
            sai_thrift_create_neighbor(self.client, self.addr_family, self.port_rifs[i], "10.10.%s.1" % str(i+1), self.mac_pool[i])
            self.nhops.append(sai_thrift_create_nhop(self.client, self.addr_family, "10.10.%s.1" % str(i+1), self.port_rifs[i]))
            sai_thrift_create_route(self.client, self.vr_id, self.addr_family, "10.10.%s.1" % str(i+1), '255.255.255.0', self.port_rifs[i])
        self.nhop_group = sai_thrift_create_next_hop_group(self.client)
        for nhop in self.nhops:
            self.nhop_gmembers.append(sai_thrift_create_next_hop_group_member(self.client, self.nhop_group, nhop))
        sai_thrift_create_route(self.client, self.vr_id, self.addr_family, "10.20.0.0", self.ip_mask, self.nhop_group)

    def teardown_ecmp_lag_group(self, first_rif_port):
        sai_thrift_remove_route(self.client, self.vr_id, self.addr_family, "10.20.0.0", self.ip_mask, self.nhop_group)
        sai_thrift_remove_route(self.client, self.vr_id, self.addr_family, "10.10.0.1", '255.255.255.0', self.lag_rif)
        for i in range(self.total_changing_ports - first_rif_port):
            sai_thrift_remove_route(self.client, self.vr_id, self.addr_family, "10.10.%s.1" % str(i+1), '255.255.255.0', self.port_rifs[i])
        for nhop_gmember in self.nhop_gmembers:
            self.client.sai_thrift_remove_next_hop_group_member(nhop_gmember)
        self.client.sai_thrift_remove_next_hop_group(self.nhop_group)
        for nhop in self.nhops:
            self.client.sai_thrift_remove_next_hop(nhop)
        del self.nhops[:]
        for i in range(self.total_changing_ports - first_rif_port):
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.port_rifs[i], "10.10.%s.1" % str(i+1), self.mac_pool[i])
        for rif in self.port_rifs:
            self.client.sai_thrift_remove_router_interface(rif)
        del self.port_rifs[:]
        for lag_member in self.lag_members:
            sai_thrift_remove_lag_member(self.client, lag_member)
        del self.lag_members[:]
        sai_thrift_remove_neighbor(self.client, self.addr_family, self.lag_rif, "10.10.0.1", self.mac_pool[self.total_changing_ports])
        self.client.sai_thrift_remove_router_interface(self.lag_rif)
        self.client.sai_thrift_remove_lag(self.lag)

    def polarizationCheck(self,packets,avg):
        if (avg < 150):
            self.assertTrue((packets >= (avg * 0.65)),"Not all paths are equally balanced, %s" % packets)
            self.assertTrue((packets <= (avg * 1.35)),"Not all paths are equally balanced, %s" % packets)
        else:
            self.assertTrue((packets >= (avg * 0.8)),"Not all paths are equally balanced, %s" % packets)
            self.assertTrue((packets <= (avg * 1.2)),"Not all paths are equally balanced, %s" % packets)

    def send_and_verify_packets(self, first_rif_port):
        exp_pkts = [0]*self.total_dst_port
        pkt_counter = [0] * self.total_dst_port
        destanation_ports = range(self.total_dst_port + 1)
        sport = 0x1234
        dport = 0x50
        src_mac_start = '00:22:22:22:{0}:{1}'
        IP_LAST_WORD_RANGE = 254
        IP_2ND_LAST_WORD_RANGE = 16
        for i in xrange(IP_LAST_WORD_RANGE):
                for j in xrange(IP_2ND_LAST_WORD_RANGE):
                    ip_src = '10.0.' + str(j) + '.' + str(i+1)
                    ip_dst = '10.20.' + str(j+1) + '.1'
                    src_mac = src_mac_start.format(str(i).zfill(4)[:2], str(i).zfill(4)[2:])
                    pkt = simple_tcp_packet(
                                            eth_dst=router_mac,
                                            eth_src=src_mac,
                                            ip_src=ip_src,
                                            ip_dst=ip_dst,
                                            ip_id=i,
                                            tcp_sport=sport,
                                            tcp_dport=dport,
                                            ip_ttl=64)
                    exp_pkt = simple_tcp_packet(
                                            eth_dst=self.mac_pool[0],
                                            eth_src=router_mac,
                                            ip_src=ip_src,
                                            ip_dst=ip_dst,
                                            ip_id=i,
                                            tcp_sport=sport,
                                            tcp_dport=dport,
                                            ip_ttl=63)
                    masked_exp_pkt = Mask(exp_pkt)
                    masked_exp_pkt.set_do_not_care_scapy(ptf.packet.Ether,"dst")

                    send_packet(self, 0, str(pkt))
                    (match_index,rcv_pkt) = verify_packet_any_port(self,masked_exp_pkt,destanation_ports)
                    logging.debug("Found expected packet from port %d" % destanation_ports[match_index])
                    pkt_counter[match_index] += 1
                    sport = random.randint(0,0xffff)
                    dport = random.randint(0,0xffff)

        #final uniform distribution check
        logging.debug(pkt_counter)
        logging.debug(first_rif_port)
        lag_packets = sum(pkt_counter[1:first_rif_port])
        lag_average = lag_packets/(len(self.lag_members) + 1)
        logging.debug("the sum of packets through the lag is " + str(lag_packets))
        logging.debug("the lag average for the lag is " + str(lag_average))
        for stat_port in range(1,first_rif_port):
            logging.debug( "PORT #"+str(stat_port)+":")
            logging.debug(str(pkt_counter[stat_port]))
            self.polarizationCheck(pkt_counter[stat_port],lag_average)
        rifs_average = sum(pkt_counter)/(len(self.port_rifs) + 1)
        logging.debug("lag average " + str(lag_average))
        self.polarizationCheck(lag_packets,rifs_average)
        for stat_port in range(first_rif_port,self.total_changing_ports):
            logging.debug( "PORT #"+str(stat_port)+":")
            logging.debug(str(pkt_counter[stat_port]))
            self.polarizationCheck(pkt_counter[stat_port],rifs_average)

    def runTest(self):
        """
        For sai server, testing different lags with router
        ---- Test for 16 ports minimun ----
        Steps
        1. Create virtual router, and rif for src port
        2. create a lag and lag rif,add ports to the lag and the rest of the ports connect to rifs
        3. configure neighbors, nhops for all of the rifs
        4. make ecmp route with all of the nhops
        5. send packets from src port
        6. check polarization check in the lag and in the ecmp
        7. remove rifs, neighbors, nhops, lag members, lag and route
        8. repeat steps 3-7 with differnt numbers of lag members and rifs
        8. clean up.
        """

        print
        print "L3MultipleEcmpLagTest"
        #general configuration
        random.seed(1)
        switch_init(self.client)
        if (len(port_list) < (self.total_dst_port + 1) ) :
            assert False, "skip this test as it requires 17 ports"

        self.src_port = port_list[0]
        for i in range (self.total_dst_port+1):
            self.mac_pool.append('00:11:22:33:44:'+str(50+i))

        self.vr_id = sai_thrift_create_virtual_router(self.client, self.v4_enabled, self.v6_enabled)
        rif_port_id = sai_thrift_create_router_interface(self.client, self.vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, self.src_port, 0, self.v4_enabled, self.v6_enabled, '')

        try:
            # The first iteration will configure port #1 as a lag with only one member
            # and will configure port #2 to port #15 as rifs,
            # the rif will advance until all of the ports will be in lag and only one if port
            for first_rif_port in range(self.first_changing_port,self.total_changing_ports):
                print "Testing with " + str(first_rif_port - 1) + " lag members."
                self.setup_ecmp_lag_group(first_rif_port)
                self.send_and_verify_packets(first_rif_port)
                self.teardown_ecmp_lag_group(first_rif_port)
        finally:

            #in case of an exception in the send_and_verify_packets
            self.teardown_ecmp_lag_group(self.total_dst_port)#check what number to send for tear down
            self.client.sai_thrift_remove_router_interface(rif_port_id)
            self.client.sai_thrift_remove_virtual_router(self.vr_id)
            print "END OF TEST"

@group('l3')
@group('1D')
@group('not-working')
@disabled
class L3BridgeAndSubPortRifTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print ""
        switch_init(self.client)
        v4_enabled = 1
        v6_enabled = 1
        vlan1_id = 10
        vlan2_id = 100
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]

        mac1 = '00:01:01:01:01:01'
        ip1 = '11.11.11.1'

        mac2 = '00:02:02:02:02:02'
        ip2 = '10.10.10.2'
        ip_addr_subnet = '10.10.10.0'
        ip_mask = '255.255.255.0'

        mac3 = '00:22:22:22:22:22'
        ip3 = '10.0.0.1'
        
        vlan1_oid = sai_thrift_create_vlan(self.client, vlan1_id)
        vlan2_oid = sai_thrift_create_vlan(self.client, vlan2_id)

        bridge_id = sai_thrift_create_bridge(self.client, SAI_BRIDGE_TYPE_1D)
        bport1_id = sai_thrift_create_bridge_sub_port(self.client, port2, bridge_id, vlan2_id)
        bport2_id = sai_thrift_create_bridge_sub_port(self.client, port3, bridge_id, vlan2_id)
        bport3_id = sai_thrift_create_bridge_sub_port(self.client, port4, bridge_id, vlan2_id)

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        
        sub_port_rif_oid = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_SUB_PORT, port1, vlan1_oid, v4_enabled, v6_enabled, '')
        bridge_rif_oid = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_BRIDGE, 0, 0, v4_enabled, v6_enabled, '')
        bridge_rif_bp = sai_thrift_create_bridge_rif_port(self.client, bridge_id, bridge_rif_oid)

        sai_thrift_create_neighbor(self.client, SAI_IP_ADDR_FAMILY_IPV4, bridge_rif_oid, ip2, mac2)
        sai_thrift_create_route(self.client, vr_id, SAI_IP_ADDR_FAMILY_IPV4, ip_addr_subnet, ip_mask, bridge_rif_oid)

        local_pkt = simple_tcp_packet(eth_src=mac2,
                                      eth_dst=mac3,
                                      dl_vlan_enable=True,
                                      vlan_vid=vlan2_id,
                                      ip_src=ip2,
                                      ip_dst=ip3,
                                      ip_id=102,
                                      ip_ttl=64)

        L3_pkt = simple_tcp_packet(eth_src=mac1,
                                   eth_dst=router_mac,
                                   ip_src=ip1,
                                   ip_dst=ip2,
                                   dl_vlan_enable=True,
                                   vlan_vid=vlan1_id,
                                   ip_id=105,
                                   ip_ttl=64)

        exp_pkt = simple_tcp_packet(eth_src=router_mac,
                                    eth_dst=mac2,
                                    ip_src=ip1,
                                    ip_dst=ip2,
                                    dl_vlan_enable=True,
                                    vlan_vid=vlan2_id,
                                    ip_id=105,
                                    ip_ttl=63)

        try:
            print "Sending packet ({} -> {}) : Sub-port rif (port 1 : vlan {}) -> Bridge rif (flooded)".format(ip1, ip2, vlan1_id)
            send_packet(self, 0, str(L3_pkt))
            verify_packets(self, exp_pkt, [1, 2, 3])
            print "Success"

            print "Sending unknown L2 packet [{} -> {}] to learn FDB and flood within a .1D bridge".format(mac1, mac3)
            send_packet(self, switch_ports[1], str(local_pkt))
            verify_packets(self, local_pkt, [2, 3])
            print "Success"

            print "Sending packet ({} -> {}) : Sub-port rif (port 1 : vlan {}) -> Bridge rif".format(ip1, ip2, vlan1_id)
            send_packet(self, 0, str(L3_pkt))
            verify_packets(self, exp_pkt, [1])
            print "Success"

        finally:
            sai_thrift_remove_route(self.client, vr_id, SAI_IP_ADDR_FAMILY_IPV4, ip_addr_subnet, ip_mask, bridge_rif_oid)
            sai_thrift_remove_neighbor(self.client, SAI_IP_ADDR_FAMILY_IPV4, bridge_rif_oid, ip2, mac2)
            self.client.sai_thrift_remove_router_interface(sub_port_rif_oid)
            self.client.sai_thrift_remove_bridge_port(bridge_rif_bp)
            self.client.sai_thrift_remove_router_interface(bridge_rif_oid)
            self.client.sai_thrift_remove_virtual_router(vr_id)

            sai_thrift_remove_bridge_sub_port(self.client, bport1_id, port2)
            sai_thrift_remove_bridge_sub_port(self.client, bport2_id, port3)
            sai_thrift_remove_bridge_sub_port(self.client, bport3_id, port4)
            self.client.sai_thrift_remove_bridge(bridge_id)

            self.client.sai_thrift_remove_vlan(vlan1_oid)
            self.client.sai_thrift_remove_vlan(vlan2_oid)

@group('l3')
@group('1D')
@group('not-working')
@disabled
class L3SubPortAndVLANRifTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print ""
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        v4_enabled = 1
        v6_enabled = 1
        vlan1_id = 10
        vlan2_id = 100
        mac_action = SAI_PACKET_ACTION_FORWARD

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:0a:00:00:00:01'

        ip_addr2 = '11.11.11.1'
        ip_addr2_subnet = '11.11.11.0'
        ip_mask2 = '255.255.255.0'
        dmac2 = '00:0b:00:00:00:01'

        vlan1_oid = sai_thrift_create_vlan(self.client, vlan1_id)
        vlan2_oid = sai_thrift_create_vlan(self.client, vlan2_id)
        vlan_member1 = sai_thrift_create_vlan_member(self.client, vlan1_oid, port1, SAI_VLAN_TAGGING_MODE_TAGGED)

        attr_value = sai_thrift_attribute_value_t(u16=vlan1_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port1, attr)

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, vlan1_oid, v4_enabled, v6_enabled, '')
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_SUB_PORT, port2, vlan2_oid, v4_enabled, v6_enabled, '')

        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)

        try:
            print "Sending packet ({} -> {}) : VLAN {} rif -> Sub-port (port 2 : vlan {}) rif".format(ip_addr1, ip_addr2, vlan1_id, vlan2_id)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src=dmac1,
                                    ip_dst=ip_addr2,
                                    ip_src=ip_addr1,
                                    ip_id=105,
                                    ip_ttl=64,
                                    dl_vlan_enable=True,
                                    vlan_vid=vlan1_id)
            exp_pkt = simple_tcp_packet(eth_dst=dmac2,
                                        eth_src=router_mac,
                                        ip_dst=ip_addr2,
                                        ip_src=ip_addr1,
                                        ip_id=105,
                                        ip_ttl=63,
                                        dl_vlan_enable=True,
                                        vlan_vid=vlan2_id)

            send_packet(self, 0, str(pkt))
            verify_packets(self, exp_pkt, [1])
            print "Success"

            print "Sending packet ({} -> {}) : Sub-port (port 2 : vlan {}) rif -> VLAN {} rif".format(ip_addr2, ip_addr1, vlan2_id, vlan1_id)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src=dmac2,
                                    ip_dst=ip_addr1,
                                    ip_src=ip_addr2,
                                    ip_id=105,
                                    ip_ttl=64,
                                    dl_vlan_enable=True,
                                    vlan_vid=vlan2_id)
            exp_pkt = simple_tcp_packet(eth_dst=dmac1,
                                        eth_src=router_mac,
                                        ip_dst=ip_addr1,
                                        ip_src=ip_addr2,
                                        ip_id=105,
                                        ip_ttl=63,
                                        dl_vlan_enable=True,
                                        vlan_vid=vlan1_id)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            print "Success"

        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_vlan_member(vlan_member1)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port1, attr)

            self.client.sai_thrift_remove_vlan(vlan1_oid)
            self.client.sai_thrift_remove_vlan(vlan2_oid)
            self.client.sai_thrift_remove_virtual_router(vr_id)

@disabled
class L3QinQRifTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
#        print "Sending packet port 1 -> port 2 (192.168.0.1 -> 10.10.10.1 [id = 101])"
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''
        outer_vlan = [0]*5
        outer_vlan[1] = 0x123
        outer_vlan[2] = 0x345

        inner_vlan = [0]*5
        inner_vlan[1] = 0x124
        inner_vlan[2] = 0x346

        vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        rif_id1 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_QINQ_PORT, port1, 0, v4_enabled, v6_enabled, mac, outer_vlan[1], inner_vlan[1])
        rif_id2 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_QINQ_PORT, port2, 0, v4_enabled, v6_enabled, mac, outer_vlan[2], inner_vlan[2])
        rif_id3 = sai_thrift_create_router_interface(self.client, vr_id, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        addr_family = SAI_IP_ADDR_FAMILY_IPV4
        ip_addr1 = '10.10.10.1'
        ip_addr1_subnet = '10.10.10.0'
        ip_mask1 = '255.255.255.0'
        dmac1 = '00:11:22:33:44:55'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)
        nhop1 = sai_thrift_create_nhop(self.client, addr_family, ip_addr1, rif_id1)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)

        ip_addr2 = '172.16.31.1'
        ip_addr2_subnet = '172.16.31.0'
        ip_mask2 = '255.255.255.0'
        dmac2 = '00:11:22:33:44:56'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)
        nhop2 = sai_thrift_create_nhop(self.client, addr_family, ip_addr2, rif_id2)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)

        ip_addr3 = '192.168.0.1'
        ip_addr3_subnet = '192.168.0.0'
        ip_mask3 = '255.255.255.0'
        dmac3 = '00:11:22:33:44:57'
        sai_thrift_create_neighbor(self.client, addr_family, rif_id3, ip_addr3, dmac3)
        nhop3 = sai_thrift_create_nhop(self.client, addr_family, ip_addr3, rif_id3)
        sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr3_subnet, ip_mask3, rif_id3)

        # send the test packet(s)
        print "QinQ RIF -> QinQ RIF"
        pkt = simple_qinq_tcp_packet(eth_dst=router_mac,
                                     eth_src=dmac1,
                                     dl_vlan_outer=outer_vlan[1],
                                     vlan_vid=inner_vlan[1],
                                     ip_dst=ip_addr2,
                                     ip_src=ip_addr1,
                                     ip_ttl=64)
        exp_pkt = simple_qinq_tcp_packet(
                                     eth_dst=dmac2,
                                     eth_src=router_mac,
                                     dl_vlan_outer=outer_vlan[2],
                                     vlan_vid=inner_vlan[2],
                                     ip_dst=ip_addr2,
                                     ip_src=ip_addr1,
                                     ip_ttl=63)

        send_packet(self, 0, str(pkt))
        verify_packets(self, exp_pkt, [1])

        print "QinQ RIF -> RIF Port"
        pkt = simple_qinq_tcp_packet(eth_dst=router_mac,
                                     eth_src=dmac2,
                                     dl_vlan_outer=outer_vlan[2],
                                     vlan_vid=inner_vlan[2],
                                     ip_dst=ip_addr3,
                                     ip_src=ip_addr2,
                                     ip_ttl=64)
        exp_pkt = simple_tcp_packet(
                                     pktlen=92,
                                     eth_dst=dmac3,
                                     eth_src=router_mac,
                                     ip_dst=ip_addr3,
                                     ip_src=ip_addr2,
                                     ip_ttl=63)
        send_packet(self, switch_ports[1], str(pkt))
        verify_packets(self, exp_pkt, [2])

        print "Port RIF -> QinQ RIF"
        pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src=dmac3,
                                ip_dst=ip_addr1,
                                ip_src=ip_addr3,
                                ip_ttl=64)
        exp_pkt = simple_qinq_tcp_packet(
                                     pktlen=108,
                                     eth_dst=dmac1,
                                     dl_vlan_outer=outer_vlan[1],
                                     vlan_vid=inner_vlan[1],
                                     eth_src=router_mac,
                                     ip_dst=ip_addr1,
                                     ip_src=ip_addr3,
                                     ip_ttl=63)
        try:
            send_packet(self,switch_ports[2], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr1_subnet, ip_mask1, rif_id1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id1, ip_addr1, dmac1)

            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr2_subnet, ip_mask2, rif_id2)
            self.client.sai_thrift_remove_next_hop(nhop2)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id2, ip_addr2, dmac2)

            sai_thrift_remove_route(self.client, vr_id, addr_family, ip_addr3_subnet, ip_mask3, rif_id3)
            self.client.sai_thrift_remove_next_hop(nhop3)
            sai_thrift_remove_neighbor(self.client, addr_family, rif_id3, ip_addr3, dmac3)

            self.client.sai_thrift_remove_router_interface(rif_id1)
            self.client.sai_thrift_remove_router_interface(rif_id2)
            self.client.sai_thrift_remove_router_interface(rif_id3)

            self.client.sai_thrift_remove_virtual_router(vr_id)

'''
    rif2(vr1) ---------
                      |
                      |
    rif3(vr2) ------------------rif1(vr1)
                      |
                      |
    rif4(vr3) ---------
'''
@group('l3')
class L3IPv4MultiVrfRouteTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''

        self.vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        self.vr2 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        self.vr3 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        self.rif_id1 = sai_thrift_create_router_interface(self.client, self.vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled, v6_enabled, mac)
        self.rif_id2 = sai_thrift_create_router_interface(self.client, self.vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port2, 0, v4_enabled, v6_enabled, mac)
        self.rif_id3 = sai_thrift_create_router_interface(self.client, self.vr2, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)
        self.rif_id4 = sai_thrift_create_router_interface(self.client, self.vr3, SAI_ROUTER_INTERFACE_TYPE_PORT, port4, 0, v4_enabled, v6_enabled, mac)

        self.addr_family = SAI_IP_ADDR_FAMILY_IPV4
        self.ip_addr1 = '10.10.10.1'
        self.ip_addr1_subnet = '10.10.10.0'
        self.ip_mask = '255.255.255.0'
        self.dmac1 = '00:11:22:33:44:55'

        # create subnet route
        sai_thrift_create_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

        try:
            self.Test1()
            self.Test2()
        finally:
            sai_thrift_remove_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            self.client.sai_thrift_remove_router_interface(self.rif_id1)
            self.client.sai_thrift_remove_router_interface(self.rif_id2)
            self.client.sai_thrift_remove_router_interface(self.rif_id3)
            self.client.sai_thrift_remove_router_interface(self.rif_id4)

            self.client.sai_thrift_remove_virtual_router(self.vr1)
            self.client.sai_thrift_remove_virtual_router(self.vr2)
            self.client.sai_thrift_remove_virtual_router(self.vr3)

    def TrafficTest(self):
        try:
            # send the test packet(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:21',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.2',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.2',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self,switch_ports[2], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:23',
                                ip_dst='10.10.10.3',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.3',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self,switch_ports[3], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            pass

    def Test1(self):
        try:
            # simulate arp entry add
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)

            sai_thrift_create_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_create_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            self.TrafficTest()
        finally:
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

    def Test2(self):
        try:
            sai_thrift_create_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_create_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

            # simulate arp entry add
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)

            self.TrafficTest()
        finally:
            sai_thrift_remove_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)


'''
    vlan_rif2(vr1) ---------
                           |
                           |
    vlan_rif3(vr2) ------------------vlan_rif1(vr1)
                           |
                           |
    vlan_rif4(vr3) ---------
'''
@group('l3')
class L3VlanIPv4MultiVrfRouteTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''
        vlan100_id = 100
        vlan200_id = 200
        vlan300_id = 300
        vlan400_id = 400

        self.addr_family = SAI_IP_ADDR_FAMILY_IPV4
        self.ip_addr1 = '10.10.10.1'
        self.ip_addr1_subnet = '10.10.10.0'
        self.ip_mask = '255.255.255.0'
        self.dmac1 = '00:11:22:33:44:55'
        self.dir_bcast_ip_addr1 = '10.10.10.255'
        self.dir_bcast_dmac1 = 'ff:ff:ff:ff:ff:ff'

        self.vlan100 = sai_thrift_create_vlan(self.client, vlan100_id)
        self.vlan200 = sai_thrift_create_vlan(self.client, vlan200_id)
        self.vlan300 = sai_thrift_create_vlan(self.client, vlan300_id)
        self.vlan400 = sai_thrift_create_vlan(self.client, vlan400_id)

        self.vlan100_member = sai_thrift_create_vlan_member(self.client, self.vlan100, port1, SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan200_member = sai_thrift_create_vlan_member(self.client, self.vlan200, port2, SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan300_member = sai_thrift_create_vlan_member(self.client, self.vlan300, port3, SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan400_member = sai_thrift_create_vlan_member(self.client, self.vlan400, port4, SAI_VLAN_TAGGING_MODE_UNTAGGED)

        attr_value = sai_thrift_attribute_value_t(u16=vlan100_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port1, attr)

        attr_value = sai_thrift_attribute_value_t(u16=vlan200_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port2, attr)

        attr_value = sai_thrift_attribute_value_t(u16=vlan300_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port3, attr)

        attr_value = sai_thrift_attribute_value_t(u16=vlan400_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port4, attr)

        sai_thrift_create_fdb(self.client, self.vlan100, self.dmac1, port1, SAI_PACKET_ACTION_FORWARD)

        self.vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        self.vr2 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)
        self.vr3 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        self.rif_id1 = sai_thrift_create_router_interface(self.client, self.vr1, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, self.vlan100, v4_enabled, v6_enabled, mac)
        self.rif_id2 = sai_thrift_create_router_interface(self.client, self.vr1, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, self.vlan200, v4_enabled, v6_enabled, mac)
        self.rif_id3 = sai_thrift_create_router_interface(self.client, self.vr2, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, self.vlan300, v4_enabled, v6_enabled, mac)
        self.rif_id4 = sai_thrift_create_router_interface(self.client, self.vr3, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, self.vlan400, v4_enabled, v6_enabled, mac)

        # create directed broadcast neighbor 
        sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.dir_bcast_ip_addr1, self.dir_bcast_dmac1)
        
        # create subnet route
        sai_thrift_create_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

        try:
            self.Test1()
            self.Test2()
        finally:
            sai_thrift_remove_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.dir_bcast_ip_addr1, self.dir_bcast_dmac1)

            self.client.sai_thrift_remove_router_interface(self.rif_id1)
            self.client.sai_thrift_remove_router_interface(self.rif_id2)
            self.client.sai_thrift_remove_router_interface(self.rif_id3)
            self.client.sai_thrift_remove_router_interface(self.rif_id4)

            self.client.sai_thrift_remove_virtual_router(self.vr1)
            self.client.sai_thrift_remove_virtual_router(self.vr2)
            self.client.sai_thrift_remove_virtual_router(self.vr3)

            sai_thrift_delete_fdb(self.client, self.vlan100, self.dmac1, port1)
            sai_thrift_flush_fdb_by_vlan(self.client, self.vlan100)
            sai_thrift_flush_fdb_by_vlan(self.client, self.vlan200)
            sai_thrift_flush_fdb_by_vlan(self.client, self.vlan300)
            sai_thrift_flush_fdb_by_vlan(self.client, self.vlan400)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port1, attr)
            self.client.sai_thrift_set_port_attribute(port2, attr)
            self.client.sai_thrift_set_port_attribute(port3, attr)
            self.client.sai_thrift_set_port_attribute(port4, attr)

            self.client.sai_thrift_remove_vlan_member(self.vlan100_member)
            self.client.sai_thrift_remove_vlan_member(self.vlan200_member)
            self.client.sai_thrift_remove_vlan_member(self.vlan300_member)
            self.client.sai_thrift_remove_vlan_member(self.vlan400_member)

            self.client.sai_thrift_remove_vlan(self.vlan100)
            self.client.sai_thrift_remove_vlan(self.vlan200)
            self.client.sai_thrift_remove_vlan(self.vlan300)
            self.client.sai_thrift_remove_vlan(self.vlan400) 

    def TrafficTest(self):
        try:
            # send the test packet(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:21',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.2',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.2',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self,switch_ports[2], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:23',
                                ip_dst='10.10.10.3',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.3',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self,switch_ports[3], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
        finally:
            pass

    def Test1(self):
        try:
            # simulate arp entry add
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)

            sai_thrift_create_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_create_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

            self.TrafficTest()
        finally:
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

    def Test2(self):
        try:
            sai_thrift_create_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_create_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)

            # simulate arp entry add
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)

            self.TrafficTest()
        finally:
            sai_thrift_remove_route(self.client, self.vr3, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_route(self.client, self.vr2, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            self.client.sai_thrift_remove_next_hop(nhop1)

@group('l3')
class L3DirBcastRouteTest(sai_base_test.ThriftInterfaceDataPlane):
    def runTest(self):
        print
        switch_init(self.client)
        port1 = port_list[0]
        port2 = port_list[1]
        port3 = port_list[2]
        port4 = port_list[3]
        v4_enabled = 1
        v6_enabled = 1
        mac_valid = 0
        mac = ''
        vlan100_id = 100

        self.addr_family = SAI_IP_ADDR_FAMILY_IPV4
        self.ip_addr1 = '10.10.10.1'
        self.ip_addr1_subnet = '10.10.10.0'
        self.ip_mask = '255.255.255.0'
        self.dmac1 = '00:11:22:33:44:55'
        self.dir_bcast_ip_addr1 = '10.10.10.255'
        self.dir_bcast_dmac1 = 'ff:ff:ff:ff:ff:ff'
        self.ip_addr2 = '20.20.20.1'
        self.ip_addr2_subnet = '20.20.20.0'
        self.dmac2 = '22:11:22:33:44:55'

        self.vlan100 = sai_thrift_create_vlan(self.client, vlan100_id)

        self.vlan100_member1 = sai_thrift_create_vlan_member(self.client, self.vlan100, port1, SAI_VLAN_TAGGING_MODE_UNTAGGED)
        self.vlan100_member2 = sai_thrift_create_vlan_member(self.client, self.vlan100, port2, SAI_VLAN_TAGGING_MODE_UNTAGGED)

        attr_value = sai_thrift_attribute_value_t(u16=vlan100_id)
        attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
        self.client.sai_thrift_set_port_attribute(port1, attr)
        self.client.sai_thrift_set_port_attribute(port2, attr)

        sai_thrift_create_fdb(self.client, self.vlan100, self.dmac1, port1, SAI_PACKET_ACTION_FORWARD)

        self.vr1 = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

        self.rif_id1 = sai_thrift_create_router_interface(self.client, self.vr1, SAI_ROUTER_INTERFACE_TYPE_VLAN, 0, self.vlan100, v4_enabled, v6_enabled, mac)
        self.rif_id2 = sai_thrift_create_router_interface(self.client, self.vr1, SAI_ROUTER_INTERFACE_TYPE_PORT, port3, 0, v4_enabled, v6_enabled, mac)

        try:
            self.Test1()
            self.Test2()
        finally:

            self.client.sai_thrift_remove_router_interface(self.rif_id1)
            self.client.sai_thrift_remove_router_interface(self.rif_id2)

            self.client.sai_thrift_remove_virtual_router(self.vr1)

            sai_thrift_delete_fdb(self.client, self.vlan100, self.dmac1, port1)
            sai_thrift_flush_fdb_by_vlan(self.client, self.vlan100)

            attr_value = sai_thrift_attribute_value_t(u16=1)
            attr = sai_thrift_attribute_t(id=SAI_PORT_ATTR_PORT_VLAN_ID, value=attr_value)
            self.client.sai_thrift_set_port_attribute(port1, attr)
            self.client.sai_thrift_set_port_attribute(port2, attr)

            self.client.sai_thrift_remove_vlan_member(self.vlan100_member1)
            self.client.sai_thrift_remove_vlan_member(self.vlan100_member2)

            self.client.sai_thrift_remove_vlan(self.vlan100)

    def TrafficTrapTest1(self):
        try:
            # send the test packet to non existing neighbors
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:21',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                ingress_port=switch_ports[2],
                packet_type=0,
                ingress_ifindex=0,
                reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_GLEAN,
                ingress_bd=0,
                inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)
            send_packet(self, switch_ports[2], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)
            verify_no_other_packets(self, timeout=1)
            
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                ingress_port=switch_ports[0],
                packet_type=0,
                ingress_ifindex=0,
                reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_GLEAN,
                ingress_bd=0,
                inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)
            send_packet(self, switch_ports[0], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)
            verify_no_other_packets(self, timeout=1)

        finally:
            pass

    def TrafficTrapTest2(self):
        try:
            # send the test packet to non existing neighbors(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:21',
                                ip_dst='10.10.10.2',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                ingress_port=switch_ports[2],
                packet_type=0,
                ingress_ifindex=0,
                reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_GLEAN,
                ingress_bd=0,
                inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)
            send_packet(self, switch_ports[2], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0])
            verify_no_other_packets(self, timeout=1)
            
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='20.20.20.2',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                ingress_port=switch_ports[0],
                packet_type=0,
                ingress_ifindex=0,
                reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_GLEAN,
                ingress_bd=0,
                inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)
            send_packet(self, switch_ports[0], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0])
            verify_no_other_packets(self, timeout=1)

        finally:
            pass

    def TrafficTest(self):
        try:       
            # send the test packet(s)
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:21',
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='00:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='10.10.10.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, switch_ports[2], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[0]])
            

            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:22',
                                ip_dst='10.10.10.255',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='ff:ff:ff:ff:ff:ff',
                                eth_src=router_mac,
                                ip_dst='10.10.10.255',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self,switch_ports[2], str(pkt))
            verify_packets(self, exp_pkt, ports=[switch_ports[0], switch_ports[1]])

            
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                eth_src='00:22:22:22:22:23',
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=64)
            exp_pkt = simple_tcp_packet(
                                eth_dst='22:11:22:33:44:55',
                                eth_src=router_mac,
                                ip_dst='20.20.20.1',
                                ip_src='192.168.0.1',
                                ip_id=105,
                                ip_ttl=63)
            send_packet(self, switch_ports[1], str(pkt))
            verify_packets(self, exp_pkt, [switch_ports[2]])
            
        finally:
            pass

    def Test1(self):
        nhop1 = 0
        nhop2 = 0

        try:
            # create subnet routes
            sai_thrift_create_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_create_route(self.client, self.vr1, self.addr_family, self.ip_addr2_subnet, self.ip_mask, self.rif_id2)
            
            self.TrafficTrapTest1()
            self.TrafficTrapTest2()
            
            # create directed broadcast neighbor on SVI rif
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.dir_bcast_ip_addr1, self.dir_bcast_dmac1)
            
            # simulate arp entry add of rif1 and 2
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id2, self.ip_addr2, self.dmac2)
            nhop2 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr2, self.rif_id2)

            self.TrafficTest()
            self.TrafficTrapTest2()

        finally:
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            if (nhop1):
                self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id2, self.ip_addr2, self.dmac2)
            if (nhop2):
                self.client.sai_thrift_remove_next_hop(nhop2)

            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.dir_bcast_ip_addr1, self.dir_bcast_dmac1)

            sai_thrift_remove_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_route(self.client, self.vr1, self.addr_family, self.ip_addr2_subnet, self.ip_mask, self.rif_id2)

    def Test2(self):
        nhop1 = 0
        nhop2 = 0

        try:
            # simulate arp entry add
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            nhop1 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr1, self.rif_id1)
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id2, self.ip_addr2, self.dmac2)
            nhop2 = sai_thrift_create_nhop(self.client, self.addr_family, self.ip_addr2, self.rif_id2)

            # create directed broadcast neighbor on SVI rif
            sai_thrift_create_neighbor(self.client, self.addr_family, self.rif_id1, self.dir_bcast_ip_addr1, self.dir_bcast_dmac1)

            # create subnet routes
            sai_thrift_create_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_create_route(self.client, self.vr1, self.addr_family, self.ip_addr2_subnet, self.ip_mask, self.rif_id2)

            self.TrafficTest()
            self.TrafficTrapTest2()
        finally:
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.ip_addr1, self.dmac1)
            if (nhop1):
                self.client.sai_thrift_remove_next_hop(nhop1)
            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id2, self.ip_addr2, self.dmac2)
            if (nhop2):
                self.client.sai_thrift_remove_next_hop(nhop2)

            sai_thrift_remove_neighbor(self.client, self.addr_family, self.rif_id1, self.dir_bcast_ip_addr1, self.dir_bcast_dmac1)

            sai_thrift_remove_route(self.client, self.vr1, self.addr_family, self.ip_addr1_subnet, self.ip_mask, self.rif_id1)
            sai_thrift_remove_route(self.client, self.vr1, self.addr_family, self.ip_addr2_subnet, self.ip_mask, self.rif_id2)

####################
class L3IPv4MYIPTrapTest(sai_base_test.ThriftInterfaceDataPlane):
    '''
    Note: Wihtout MYIP_SUBNET feature pleaes run
          trafficHostRouteMYIPTest()
          trafficSubnetRouteMYIPTest()

                   Or

          With MYIP_SUBNET fature please run
          trafficHostRouteMYIPTest()
          trafficSubnetRouteMYIPSubnetTest()
    '''
    def runTest(self):
       switch_init(self.client)

       addr_family = SAI_IP_ADDR_FAMILY_IPV4
       ip_addr_host = '10.10.10.1'
       ip_addr_subnet = '10.10.10.0'
       ip_mask_32 = '255.255.255.255'
       ip_mask_24 = '255.255.255.0'

       port1 = port_list[1]
       v4_enabled = 1
       v6_enabled = 1
       mac = ''

       #creating virtual router
       vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

       #creating routing interface
       rif_id = sai_thrift_create_router_interface(self.client, vr_id,
                     SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled,
                     v6_enabled, mac)


       #create nexthop
       cpu_port_next_hop = sai_thrift_get_cpu_port_id(self.client)
       router_packet_action = SAI_PACKET_ACTION_FORWARD

       #creating route
       sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr_host,
                          ip_mask_32, cpu_port_next_hop, router_packet_action)

       sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr_subnet,
                          ip_mask_24, cpu_port_next_hop, router_packet_action)

       #creating the trap group and trap
       trap_group_host = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
       trap_group_subnet = sai_thrift_create_hostif_trap_group(self.client, queue_id=5)

       #creating IP2ME trap
       trap_host = sai_thrift_create_hostif_trap(self.client,
                                     trap_type=SAI_HOSTIF_TRAP_TYPE_IP2ME,
                                     packet_action=SAI_PACKET_ACTION_TRAP,
                                     trap_group=trap_group_host)


       def trafficHostRouteMYIPTest():
            print("")
            print("Testing IPv4 IP2ME")
            print("Sending packet to CPU using MYIP trap")
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='10.10.10.1',
                                    ip_src='192.168.0.1',
                                    ip_ttl=63)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                      ingress_port=switch_ports[1],
                      packet_type=0,
                      ingress_ifindex=0,
                      ingress_bd=0,
                      reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_MYIP,
                      inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)

       def trafficSubnetRouteMYIPTest():
            print("")
            print("Testing IPv4 IP2ME Subnet")
            print("Sending packet to CPU using MYIP SUBNET trap")
            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='10.10.10.2',
                                    ip_src='192.168.0.1',
                                    ip_ttl=63)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                      ingress_port=switch_ports[1],
                      packet_type=0,
                      ingress_ifindex=0,
                      ingress_bd=0,
                      reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_MYIP,
                      inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)

       def trafficSubnetRouteMYIPSubnetTest():
            '''
            Test case to MYIP_SUBNET feature in SAI
            Not currently present in our SAI release
            '''
            SAI_HOSTIF_TRAP_TYPE_IP2ME_SUBNET = 0x00004007

            print("")
            print("Testing IPv4 IP2ME Subnet")
            print("Sending packet to CPU using MYIP SUBNET trap")

            #Creating IP2ME_SUBNET trap
            trap_subnet = sai_thrift_create_hostif_trap(self.client,
                                      trap_type=SAI_HOSTIF_TRAP_TYPE_IP2ME_SUBNET,
                                      packet_action=SAI_PACKET_ACTION_TRAP,
                                      trap_group=trap_group_subnet)

            pkt = simple_tcp_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ip_dst='10.10.10.2',
                                    ip_src='192.168.0.1',
                                    ip_ttl=63)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                      ingress_port=switch_ports[1],
                      packet_type=0,
                      ingress_ifindex=0,
                      ingress_bd=0,
                      reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_MYIP_SUBNET,
                      inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)

       try:
            trafficHostRouteMYIPTest()

            print("Waiting for 5 Secs..")
            time.sleep(5)

            trafficSubnetRouteMYIPTest()

            '''
            Test case to MYIP_SUBNET feature in SAI.
            Not currently present in our SAI release

            print("Waiting for 5 Secs..")
            time.sleep(5)

            trafficSubnetRouteMYIPSubnetTest()
            '''
       finally:
            #remove routes
            sai_thrift_remove_route(self.client, vr_id, addr_family,
                        ip_addr_host, ip_mask_32, cpu_port_next_hop)
            sai_thrift_remove_route(self.client, vr_id, addr_family,
                        ip_addr_subnet, ip_mask_24, cpu_port_next_hop)

            #remove port and virtual router
            self.client.sai_thrift_remove_router_interface(rif_id)
            self.client.sai_thrift_remove_virtual_router(vr_id)

            #remvoe traps
            sai_thrift_remove_hostif_trap(self.client, trap_host)
            '''
            Test case to MYIP_SUBNET feature in SAI.
            Not currently present in our SAI release
            '''
            #sai_thrift_remove_hostif_trap(self.client, trap_subnet)

            #remove the trap group
            sai_thrift_remove_hostif_trap_group(self.client, trap_group_host)
            sai_thrift_remove_hostif_trap_group(self.client, trap_group_subnet)


############## End of L3IPv4MYIPTrapTest ###############

class L3IPv6MYIPTrapTest(sai_base_test.ThriftInterfaceDataPlane):
    '''
    Note: Wihtout MYIP_SUBNET feature pleaes run
          trafficHostRouteMYIPTest()
          trafficSubnetRouteMYIPTest()

                   Or

          With MYIP_SUBNET fature please run
          trafficHostRouteMYIPTest()
          trafficSubnetRouteMYIPSubnetTest()
    '''
    def runTest(self):
       switch_init(self.client)

       addr_family = SAI_IP_ADDR_FAMILY_IPV6
       ip_addr_host = '1234:5678:9abc:def0:4422:1133:5577:99aa'
       ip_mask_host = 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff'
       ip_addr_subnet = '1234:5678:9abc:def0:4422:1133:5577:0'
       ip_mask_subnet = 'ffff:ffff:ffff:ffff:ffff:ffff:ffff:0'

       port1 = port_list[1]
       v4_enabled = 1
       v6_enabled = 1
       mac = ''

       #creating virtual router
       vr_id = sai_thrift_create_virtual_router(self.client, v4_enabled, v6_enabled)

       #creating routing interface
       rif_id = sai_thrift_create_router_interface(self.client, vr_id,
                     SAI_ROUTER_INTERFACE_TYPE_PORT, port1, 0, v4_enabled,
                     v6_enabled, mac)


       #create nexthop
       cpu_port_next_hop = sai_thrift_get_cpu_port_id(self.client)
       router_packet_action = SAI_PACKET_ACTION_FORWARD

       #creating route
       sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr_host,
                        ip_mask_host, cpu_port_next_hop, router_packet_action)

       sai_thrift_create_route(self.client, vr_id, addr_family, ip_addr_subnet,
                        ip_mask_subnet, cpu_port_next_hop, router_packet_action)

       #creating the trap group and trap
       trap_group_host = sai_thrift_create_hostif_trap_group(self.client, queue_id=4)
       trap_group_subnet = sai_thrift_create_hostif_trap_group(self.client, queue_id=5)

       #creating IP2ME trap
       trap_host = sai_thrift_create_hostif_trap(self.client,
                                     trap_type=SAI_HOSTIF_TRAP_TYPE_IP2ME,
                                     packet_action=SAI_PACKET_ACTION_TRAP,
                                     trap_group=trap_group_host)

       def trafficHostRouteMYIPTest():
            print("")
            print("Testing IPv6 IP2ME with host IP")
            print("Sending packet to CPU using MYIP trap")
            pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99aa',
                                    ipv6_src='2000::1',
                                    ipv6_hlim=63)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                      ingress_port=switch_ports[1],
                      packet_type=0,
                      ingress_ifindex=0,
                      ingress_bd=0,
                      reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_MYIP,
                      inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)


       def trafficSubnetRouteMYIPTest():
            print("")
            print("Testing IPv6 IP2ME with Subnet")
            print("Sending packet to CPU using MYIP SUBNET trap")

            pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99a3',
                                    ipv6_src='2000::1',
                                    ipv6_hlim=63)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                      ingress_port=switch_ports[1],
                      packet_type=0,
                      ingress_ifindex=0,
                      ingress_bd=0,
                      reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_MYIP,
                      inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)

       def trafficSubnetRouteMYIPSubnetTest():
            '''
            Test case to MYIP_SUBNET feature in SAI
            Not currently present in our SAI release
            '''
            SAI_HOSTIF_TRAP_TYPE_IP2ME_SUBNET = 0x00004007

            print("")
            print("Testing IPv6 IP2ME Subnet")
            print("Sending packet to CPU using MYIP SUBNET trap")

            #Creating IP2ME_SUBNET trap
            trap_subnet = sai_thrift_create_hostif_trap(self.client,
                                           trap_type=SAI_HOSTIF_TRAP_TYPE_IP2ME_SUBNET,
                                           packet_action=SAI_PACKET_ACTION_TRAP,
                                          trap_group=trap_group_subnet)


            pkt = simple_tcpv6_packet(eth_dst=router_mac,
                                    eth_src='00:22:22:22:22:22',
                                    ipv6_dst='1234:5678:9abc:def0:4422:1133:5577:99a5',
                                    ipv6_src='2000::1',
                                    ipv6_hlim=63)
            exp_pkt = pkt.copy()
            cpu_pkt = simple_cpu_packet(
                      ingress_port=switch_ports[1],
                      packet_type=0,
                      ingress_ifindex=0,
                      ingress_bd=0,
                      reason_code=SWITCH_HOSTIF_TRAP_ATTR_TYPE_MYIP_SUBNET,
                      inner_pkt=exp_pkt)
            cpu_pkt = cpu_packet_mask_ingress_bd_and_ifindex(cpu_pkt)

            send_packet(self, switch_ports[1], str(pkt))
            verify_packet(self, cpu_pkt, cpu_ports[0], timeout=1)

       try:
            trafficHostRouteMYIPTest()

            print("Waiting for 5 Secs..")
            time.sleep(5)

            trafficSubnetRouteMYIPTest()

            '''
            Test case to MYIP_SUBNET feature in SAI.
            Not currently present in our SAI release

            print("Waiting for 5 Secs..")
            time.sleep(5)

            trafficSubnetRouteMYIPSubnetTest()
            '''

       finally:
            #remove routes
            sai_thrift_remove_route(self.client, vr_id, addr_family,
                        ip_addr_host, ip_mask_host, cpu_port_next_hop)
            sai_thrift_remove_route(self.client, vr_id, addr_family,
                        ip_addr_subnet, ip_mask_subnet, cpu_port_next_hop)

            #remove port and virtual router
            self.client.sai_thrift_remove_router_interface(rif_id)
            self.client.sai_thrift_remove_virtual_router(vr_id)

            #remvoe traps
            sai_thrift_remove_hostif_trap(self.client, trap_host)
            '''
            Test case to MYIP_SUBNET feature in SAI
            Not currently present in our SAI release
            '''
            #sai_thrift_remove_hostif_trap(self.client, trap_subnet)

            #remove the trap group
            sai_thrift_remove_hostif_trap_group(self.client, trap_group_host)
            sai_thrift_remove_hostif_trap_group(self.client, trap_group_subnet)

############## End of L3IPv6MYIPTrapTest ###############
