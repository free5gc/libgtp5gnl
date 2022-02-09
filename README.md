# libgtp5gnl - netlink library for Linux kernel module 5G GTP-U

In order to control the kernel-side GTP-U plane, a netlink based control
interface between GTP-C in userspace and GTP-U in kernelspace was invented.

The encoding and decoding of these control messages is implemented in
the libgtp5gnl (library for GTP netlink).

libgtp5gnl is a project based on [libgtpnl](https://github.com/osmocom/libgtpnl)
which is part of the [Osmocom](https://osmocom.org/) Open Source Mobile
Communications project.

## Usage
### Compile
```
autoreconf -iv
./configure --prefix=`pwd`
make
```

### Command
Sample command is written under `script/` and `tools/gtp5g-tunnel.c`.

### Show Current Rules
```
sudo ./tools/gtp5g-tunnel list pdr
sudo ./tools/gtp5g-tunnel list far
sudo ./tools/gtp5g-tunnel list qer
```

### get/del/add/mod PDR/FAR/QER
```
sudo ./gtp5g-tunnel [get/del/add/mod] [PDR/FAR/QER] [interface_name] [seid] [id] [option]
e.g.  sudo ./gtp5g-tunnel add pdr upfgtp 0 1 --pcd 99
```
```
PDR OPTIONS

        --pcd <precedence>

        --hdr-rm <outer-header-removal>

        --far-id <existed-far-id>

        --ue-ipv4 <pdi-ue-ipv4>

        --f-teid <i-teid> <local-gtpu-ipv4>

        --sdf-desp <description-string>

                ex: --sdf-desp 'permit out ip from 192.168.0.1 22,53,73 to 127.0.0.1/24'

        --sdf-tos-traff-cls <tos-traffic-class>

        --sdf-scy-param-idx <security-param-idx>

        --sdf-flow-label <flow-label>

        --sdf-id <id>

        --qer-id <id>

FAR OPTIONS

        --action <apply-action>

        --hdr-creation <description> <o-teid> <peer-ipv4> <peer-port>

        --fwd-policy <mark set in iptable>

                Set mark into packet and exec Linux routing>

QER OPTIONS

        --qer-id <qer-id>

        --qfi-id <qfi-id> [Value range: {0..63}]

        --rqi-d <rqi> [Value range: {0=not triggered, 1=triggered}]

        --ppp <ppp> [Value range: {0=not present, 1=present}]

        --ppi <ppi> [Value range: {0..7}]
```
### Test
Simple Test (RAN + UPF)
```
./run.sh SimpleUPTest
```

ULCL Test (RAN + I-UPF + A-UPF)
```
./run.sh ULCLTest1
```

### Change Log
#### v0.2.0
+ Changed to host type between gtp5g and libgtp5gnl
+ Supported forwarding policy feature, but need to set `ip rule` and `ip route` with Linux mark by self
+ Fixed bugs about "any" and "assigned" in SDF filter
+ Fixed bugs about netmask translation between gtp5g and libgtp5gnl in SDF filter

#### v0.1.0
+ First version
+ Supported packet matching about UE IP, TEID and SDF filter