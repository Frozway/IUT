# Alexis BARON C1 @10.192.51.14

Commande : `service ssh status`
Result :
```
Unit ssh.service could not be found.
```

Commande : `sudo apt-get install openssh-server`


Commande : `sudo cp /etc/sshd_config.bak /etc/sshd_config`
```
ssh admin@10.192.51.14
admin@10.192.51.14's password:
```
On voit qu'on est connecté à la machine physique
```
admin@sparc04:~
```

## Question 1 

Résultat

```
No.     Time           Source                Destination           Protocol Length Info
      1 0.000000000    fe80::d57c:4fac:bc43:b595 ff02::fb              MDNS     107    Standard query 0x0000 PTR _ipps._tcp.local, "QM" question PTR _ipp._tcp.local, "QM" question
      2 0.001086191    0.0.0.0               255.255.255.255       DHCP     342    DHCP Discover - Transaction ID 0x571c5d33
      3 0.109371279    fe80::e29:efff:fedd:2fc1 ff02::1:ff28:a201     ICMPv6   86     Neighbor Solicitation for fe80::704d:bed1:d028:a201 from 0c:29:ef:dd:2f:c1
      4 0.878113190    fe80::e29:efff:fedd:2fc1 ff02::1:ff8a:a64c     ICMPv6   86     Neighbor Solicitation for fe80::72b5:e8ff:fe8a:a64c from 0c:29:ef:dd:2f:c1
      5 1.011973849    10.192.0.250          224.0.0.18            VRRP     70     Announcement (v2)
      6 1.083869709    HewlettP_aa:0a:a5     Spanning-tree-(for-bridges)_00 STP      119    MST. Root = 0/0/00:1f:fe:7e:ac:00  Cost = 25000  Port = 0x805b
      7 1.130330594    Vmware_87:c2:4e       Broadcast             RARP     60     Who is 00:50:56:87:c2:4e? Tell 00:50:56:87:c2:4e
      8 1.406569925    ::                    ff02::16              ICMPv6   130    Multicast Listener Report Message v2
      9 1.407184076    ::                    ff02::fb              ICMPv6   90     Multicast Listener Query
     10 1.421200320    ::                    ff02::16              ICMPv6   130    Multicast Listener Report Message v2
     11 1.430369274    0.0.0.0               255.255.255.255       DHCP     342    DHCP Discover - Transaction ID 0xa26c631a
     12 1.750069145    ::                    ff02::16              ICMPv6   110    Multicast Listener Report Message v2
     13 2.102138315    ::                    ff02::1:ff2a:c309     ICMPv6   86     Neighbor Solicitation for fe80::c56c:8ebd:292a:c309
     14 2.416273837    ::                    ff02::fb              ICMPv6   90     Multicast Listener Query
     15 3.021788089    10.192.0.250          224.0.0.18            VRRP     70     Announcement (v2)
     16 3.084235616    HewlettP_aa:0a:a5     Spanning-tree-(for-bridges)_00 STP      119    MST. Root = 0/0/00:1f:fe:7e:ac:00  Cost = 25000  Port = 0x805b
     17 3.132172156    fe80::c56c:8ebd:292a:c309 ff02::16              ICMPv6   110    Multicast Listener Report Message v2
     18 3.152675156    fe80::c56c:8ebd:292a:c309 ff02::16              ICMPv6   110    Multicast Listener Report Message v2
     19 3.173265913    fe80::c56c:8ebd:292a:c309 ff02::16              ICMPv6   110    Multicast Listener Report Message v2
     20 3.282229152    fe80::c56c:8ebd:292a:c309 ff02::fb              MDNS     204    Standard query response 0x0000 PTR, cache flush archi000-2.local AAAA, cache flush fe80::c56c:8ebd:292a:c309
```

Le protocole le plus haut capturé est DHCP qui se situe sur la première couche
Le procole le plus bas utilisé commun à toutes les trames est RARP


2.a
Après avoir mis le filtre eth.addr, on obtient seulement les trames envoyées ou destinées à la machine. Cependant, il faut rajouter == 6c:2b:59:ea:c3:f0 pour appliquer le filtre seulement à la carte ethernet de la machine physique
b.
```
No.     Time           Source                Destination           Protocol Length Info
    152 8.038759849    10.192.51.94          10.192.51.14          SSH      110    Client: Encrypted packet (len=44)

Frame 152: 110 bytes on wire (880 bits), 110 bytes captured (880 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 1, Ack: 1, Len: 44
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    153 8.039767537    10.192.51.14          10.192.51.94          SSH      110    Server: Encrypted packet (len=44)

Frame 153: 110 bytes on wire (880 bits), 110 bytes captured (880 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 1, Ack: 45, Len: 44
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    154 8.039816201    10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=45 Ack=45 Win=501 Len=0 TSval=1960003088 TSecr=3637032236

Frame 154: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 45, Ack: 45, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    156 8.295207088    10.192.51.94          10.192.51.14          SSH      110    Client: Encrypted packet (len=44)

Frame 156: 110 bytes on wire (880 bits), 110 bytes captured (880 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 45, Ack: 45, Len: 44
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    157 8.296352005    10.192.51.14          10.192.51.94          SSH      118    Server: Encrypted packet (len=52)

Frame 157: 118 bytes on wire (944 bits), 118 bytes captured (944 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 45, Ack: 89, Len: 52
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    158 8.296403623    10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=89 Ack=97 Win=501 Len=0 TSval=1960003345 TSecr=3637032492

Frame 158: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 89, Ack: 97, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    160 8.708381407    10.192.51.94          10.192.51.14          SSH      110    Client: Encrypted packet (len=44)

Frame 160: 110 bytes on wire (880 bits), 110 bytes captured (880 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 89, Ack: 97, Len: 44
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    161 8.708843148    10.192.51.14          10.192.51.94          SSH      134    Server: Encrypted packet (len=68)

Frame 161: 134 bytes on wire (1072 bits), 134 bytes captured (1072 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 97, Ack: 133, Len: 68
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    162 8.708857351    10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=133 Ack=165 Win=501 Len=0 TSval=1960003757 TSecr=3637032905

Frame 162: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 133, Ack: 165, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    261 14.619483110   10.192.51.94          10.192.51.14          SSH      102    Client: Encrypted packet (len=36)

Frame 261: 102 bytes on wire (816 bits), 102 bytes captured (816 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 133, Ack: 165, Len: 36
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    262 14.620407073   10.192.51.14          10.192.51.94          SSH      102    Server: Encrypted packet (len=36)

Frame 262: 102 bytes on wire (816 bits), 102 bytes captured (816 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 165, Ack: 169, Len: 36
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    263 14.620449521   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=201 Win=501 Len=0 TSval=1960009669 TSecr=3637038816

Frame 263: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 201, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    265 14.653178320   10.192.51.14          10.192.51.94          SSH      166    Server: Encrypted packet (len=100)

Frame 265: 166 bytes on wire (1328 bits), 166 bytes captured (1328 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 201, Ack: 169, Len: 100
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    266 14.653197528   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=301 Win=501 Len=0 TSval=1960009702 TSecr=3637038849

Frame 266: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 301, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    269 14.690987002   10.192.51.14          10.192.51.94          SSH      190    Server: Encrypted packet (len=124)

Frame 269: 190 bytes on wire (1520 bits), 190 bytes captured (1520 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 301, Ack: 169, Len: 124
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    270 14.691003736   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=425 Win=501 Len=0 TSval=1960009740 TSecr=3637038887

Frame 270: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 425, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    272 15.657455523   10.192.51.14          10.192.51.94          SSH      190    Server: Encrypted packet (len=124)

Frame 272: 190 bytes on wire (1520 bits), 190 bytes captured (1520 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 425, Ack: 169, Len: 124
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    273 15.657511403   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=549 Win=501 Len=0 TSval=1960010706 TSecr=3637039853

Frame 273: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 549, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    284 16.659289799   10.192.51.14          10.192.51.94          SSH      190    Server: Encrypted packet (len=124)

Frame 284: 190 bytes on wire (1520 bits), 190 bytes captured (1520 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 549, Ack: 169, Len: 124
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    285 16.659332390   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=673 Win=501 Len=0 TSval=1960011708 TSecr=3637040855

Frame 285: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 673, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    296 17.661006838   10.192.51.14          10.192.51.94          SSH      358    Server: Encrypted packet (len=292)

Frame 296: 358 bytes on wire (2864 bits), 358 bytes captured (2864 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 673, Ack: 169, Len: 292
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    297 17.661058230   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=965 Win=501 Len=0 TSval=1960012710 TSecr=3637041857

Frame 297: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 965, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    298 17.661941126   10.192.51.14          10.192.51.94          SSH      166    Server: Encrypted packet (len=100)

Frame 298: 166 bytes on wire (1328 bits), 166 bytes captured (1328 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 965, Ack: 169, Len: 100
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    299 17.661963506   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=169 Ack=1065 Win=501 Len=0 TSval=1960012710 TSecr=3637041858

Frame 299: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 1065, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    323 21.882845597   10.192.51.94          10.192.51.14          SSH      134    Client: Encrypted packet (len=68)

Frame 323: 134 bytes on wire (1072 bits), 134 bytes captured (1072 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 169, Ack: 1065, Len: 68
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    324 21.883213224   10.192.51.14          10.192.51.94          SSH      174    Server: Encrypted packet (len=108)

Frame 324: 174 bytes on wire (1392 bits), 174 bytes captured (1392 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 1065, Ack: 237, Len: 108
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    325 21.883224942   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=237 Ack=1173 Win=501 Len=0 TSval=1960016932 TSecr=3637046079

Frame 325: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 237, Ack: 1173, Len: 0

No.     Time           Source                Destination           Protocol Length Info
    357 26.777690789   10.192.51.94          10.192.51.14          SSH      134    Client: Encrypted packet (len=68)

Frame 357: 134 bytes on wire (1072 bits), 134 bytes captured (1072 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 237, Ack: 1173, Len: 68
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    358 26.778104007   10.192.51.14          10.192.51.94          SSH      174    Server: Encrypted packet (len=108)

Frame 358: 174 bytes on wire (1392 bits), 174 bytes captured (1392 bits) on interface 0
Ethernet II, Src: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0), Dst: PcsCompu_17:51:94 (08:00:27:17:51:94)
Internet Protocol Version 4, Src: 10.192.51.14, Dst: 10.192.51.94
Transmission Control Protocol, Src Port: 22, Dst Port: 50682, Seq: 1173, Ack: 305, Len: 108
SSH Protocol

No.     Time           Source                Destination           Protocol Length Info
    359 26.778115503   10.192.51.94          10.192.51.14          TCP      66     50682 → 22 [ACK] Seq=305 Ack=1281 Win=501 Len=0 TSval=1960021827 TSecr=3637050974

Frame 359: 66 bytes on wire (528 bits), 66 bytes captured (528 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Dell_ea:c3:f0 (6c:2b:59:ea:c3:f0)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.51.14
Transmission Control Protocol, Src Port: 50682, Dst Port: 22, Seq: 305, Ack: 1281, Len: 0
```

c. Les 2 protocoles qui s'affichent sont le protocole SSH et le protocole TCP

3.a:
L'adresse ip source 10.192.51.94 correspond à l'adresse ip de la machine virtuelle. Lorsque l'on clique sur la trame, on peut récupérer l'adresse MAC de la VM. Il s'agit de 08:00:27:17:51:94. C'est sur la 2ème ligne

```
Frame 9: 98 bytes on wire (784 bits), 98 bytes captured (784 bits) on interface 0
Ethernet II, Src: PcsCompu_17:51:94 (08:00:27:17:51:94), Dst: Hp-UxE90_53:e0:e2 (00:10:83:53:e0:e2)
    Destination: Hp-UxE90_53:e0:e2 (00:10:83:53:e0:e2)
    Source: PcsCompu_17:51:94 (08:00:27:17:51:94)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 10.192.51.94, Dst: 10.192.50.49
Internet Control Message Protocol
```

b.
@10.192.50.49
00:10:83:53:e0:e2

c.
```
0000   00 10 83 53 e0 e2 08 00 27 17 51 94 08 00 45 00
0010   00 54 3b 27 40 00 40 01 84 73 0a c0 33 5e 0a c0
0020   32 31 08 00 f3 25 17 8e 00 01 46 5f ff 63 00 00
0030   00 00 dd b4 0b 00 00 00 00 00 10 11 12 13 14 15
0040   16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25
0050   26 27 28 29 2a 2b 2c 2d 2e 2f 30 31 32 33 34 35
0060   36 37
```

d. Il n'est pas présenté car si le code erreur est faux, la trame n'est pas reçu par la machine car c'est la carte elle-même qui gère cela.

## Question 2


