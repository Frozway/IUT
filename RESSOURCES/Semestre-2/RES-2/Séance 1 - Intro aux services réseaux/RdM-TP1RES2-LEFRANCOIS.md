RdM-TP1RES2-LEFRANCOIS.md 1/25/2023

Thibaut LEFRANCOIS D2![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.001.png)

**Adresse IP physique : 10.192.51.111 Adresse IP virtuel : 10.192.51.31**

RES2 - TP 1 Réseaux![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.002.png)

Elements préalables

Question 1 :

id -n -u est une **commande** qui utilise "ID" accompagné de paramètres pour afficher le nom de l'utilisateur sur lequel on se trouve, et on est bien sur **admin**

Découverte de la salle réseau

Question 2 :

Je suis connecté au précâblage général pour le réseau de l'IUT et plus précisement sur la piste numéro 1

Découverte des commandes réseaux de base sous Linux

Question 4 :

**Adresse IP et MAC de la machine physique :**

- Carte réseau 1 (docker0) :
  - IP : 172.17.01 / MAC : 02:42:99:a5:83:4a
- Carte réseau 2 (eno1):
  - IP : 10.192.51.111 / MAC : 6c:2b:59:ea:c4:0e
- Carte réseau 3 :
  - MAC : 00:13:3b:4a:2d:58
- Carte réseau 3 :
  - IP : 127.0.0.1

Résultat PHYSIQUE :

docker0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500 ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.003.png)

`        `inet 172.17.0.1  netmask 255.255.0.0  broadcast 172.17.255.255         ether 02:42:99:a5:83:4a  txqueuelen 0  (Ethernet) 

`        `RX packets 0  bytes 0 (0.0 B) 

`        `RX errors 0  dropped 0  overruns 0  frame 0 

`        `TX packets 0  bytes 0 (0.0 B) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

eno1: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500 

`        `inet 10.192.51.111  netmask 255.255.0.0  broadcast 10.192.255.255         inet6 fe80::cf66:ae6a:a6df:ca9a  prefixlen 64  scopeid 0x20<link>         ether 6c:2b:59:ea:c4:0e  txqueuelen 1000  (Ethernet) ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.004.png)

`        `RX packets 181891  bytes 215072220 (215.0 MB) 

`        `RX errors 0  dropped 32  overruns 0  frame 0 

`        `TX packets 39933  bytes 5294383 (5.2 MB) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

`        `device interrupt 16  memory 0x92c00000-92c20000   

ens1: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500 

`        `ether 00:13:3b:4a:2d:58  txqueuelen 1000  (Ethernet) 

`        `RX packets 0  bytes 0 (0.0 B) 

`        `RX errors 0  dropped 0  overruns 0  frame 0 

`        `TX packets 0  bytes 0 (0.0 B) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536 

`        `inet 127.0.0.1  netmask 255.0.0.0 

`        `inet6 ::1  prefixlen 128  scopeid 0x10<host> 

`        `loop  txqueuelen 1000  (Boucle locale) 

`        `RX packets 49  bytes 4869 (4.8 KB) 

`        `RX errors 0  dropped 0  overruns 0  frame 0 

`        `TX packets 49  bytes 4869 (4.8 KB) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

**Adresse IP et MAC de la machine virtuel :**

- Carte réseau 1 (enp0s3) :
  - IP : 10.192.51.31 / MAC : 08:00:27:17:51:31
- Carte réseau 2 (enp0s8):
  - MAC : 08:00:27:17:51:11
- Carte réseau 3 (lo) :
  - IP : 127.0.0.1

Résultats machine virtuel :

enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500 ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.005.png)

`        `inet 10.192.51.31  netmask 255.255.0.0  broadcast 10.192.255.255         inet6 fe80::4d98:59a4:36d5:4255  prefixlen 64  scopeid 0x20<link>         ether 08:00:27:17:51:31  txqueuelen 1000  (Ethernet) 

`        `RX packets 53642  bytes 66703039 (66.7 MB) 

`        `RX errors 0  dropped 0  overruns 0  frame 0 

`        `TX packets 15683  bytes 2405743 (2.4 MB) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

enp0s8: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500 

`        `inet6 fe80::3c47:6632:f407:ce06  prefixlen 64  scopeid 0x20<link>         ether 08:00:27:17:51:11  txqueuelen 1000  (Ethernet) 

`        `RX packets 0  bytes 0 (0.0 B) 

`        `RX errors 0  dropped 0  overruns 0  frame 0 

`        `TX packets 811  bytes 138303 (138.3 KB) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536 

`        `inet 127.0.0.1  netmask 255.0.0.0 

`        `inet6 ::1  prefixlen 128  scopeid 0x10<host> 

`        `loop  txqueuelen 1000  (Local Loopback) 

`        `RX packets 258  bytes 31190 (31.1 KB) 

`        `RX errors 0  dropped 0  overruns 0  frame 0 

`        `TX packets 258  bytes 31190 (31.1 KB) 

`        `TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0 

Question 5 :

Les adresses IP "eno1" et "enp0s3" ont la même adresse de réseau

Question 6 :

ifconfig -a permet d'afficher toutes les cartes réseaux existantes même si l'une d'entres elles est désactiver (comme docker0 après l'entrée de la commande)

Question 7 :

Les **FQMN** obetnus ont le nom du domaine complet en commun qui est **"192.10.in-addr.arpa"** (soit : ".univ- lr.fr.").

J'en déduis que pour la machine virtuel le nom sera "vmarm001" et pour la machine physique "arm001".

Effectivement on trouve le même résulta mais uniquement sur la machine phyisique. Sur la machine virtuel, après l'entrée de la commande, on obtient archi000

Question 8 :

On remarque en exécutant la commande nslookup serverrx.univ-lr.fr que l'adresse IP du serveur a en commun le début de l'adresse IP contenant l'ID de réseau **(10.192)**.

Question 9 :

Suite à l'exécution de la commande nslookup impll304 on voit que l'IP de l'imprimante "impll304" est **10.192.50.49** et son FQMN est **"impll304.univ-lr.fr"**.

Ils ont en commun le nom de domaine **".univ-lr.fr"**.

Question 10 :

J'execute la commande nslookup www.univ-larochelle.fr et je constate que l'adresse IP n'est pas similaire a celles trouvées précédemment car le site ne doit pas être hébergé sur le même serveur bien que le nom de domaine soit le même.

Question 11 :

Voici le résultat après exécution de la commande **ping 10.192.51.31** (pour l'adresse IP de enp0s3) :

PING 10.192.51.31 (10.192.51.31) 56(84) bytes of data. ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.006.png)

64 bytes from 10.192.51.31: icmp\_seq=1 ttl=64 time=0.024 ms 

64 bytes from 10.192.51.31: icmp\_seq=2 ttl=64 time=0.150 ms 

64 bytes from 10.192.51.31: icmp\_seq=3 ttl=64 time=0.067 ms 

64 bytes from 10.192.51.31: icmp\_seq=4 ttl=64 time=0.067 ms 

64 bytes from 10.192.51.31: icmp\_seq=5 ttl=64 time=0.060 ms 

64 bytes from 10.192.51.31: icmp\_seq=6 ttl=64 time=0.067 ms 

64 bytes from 10.192.51.31: icmp\_seq=7 ttl=64 time=0.091 ms 

64 bytes from 10.192.51.31: icmp\_seq=8 ttl=64 time=0.075 ms 

64 bytes from 10.192.51.31: icmp\_seq=9 ttl=64 time=0.066 ms 

64 bytes from 10.192.51.31: icmp\_seq=10 ttl=64 time=0.048 ms 

64 bytes from 10.192.51.31: icmp\_seq=11 ttl=64 time=0.067 ms 

64 bytes from 10.192.51.31: icmp\_seq=12 ttl=64 time=0.028 ms 

64 bytes from 10.192.51.31: icmp\_seq=13 ttl=64 time=0.068 ms 

64 bytes from 10.192.51.31: icmp\_seq=14 ttl=64 time=0.065 ms 

^C 

--- 10.192.51.31 ping statistics --- 

14 packets transmitted, 14 received, 0% packet loss, time 13331ms rtt min/avg/max/mdev = 0.024/0.067/0.150/0.029 ms 

Question 12 :

Pour limiter le nombre de demande d'écho on rajoute le paramètre -c à la commande tel que **ping -c 3 10.192.51.111** (pour l'adresse ip de eno1) (3 représente le nombre d'échos qu'on souhaite".

On obtient alors :

PING 10.192.51.111 (10.192.51.111) 56(84) bytes of data. ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.007.png)

64 octets de 10.192.51.111 : icmp\_seq=1 ttl=64 temps=0.066 ms 

64 octets de 10.192.51.111 : icmp\_seq=2 ttl=64 temps=0.064 ms 

64 octets de 10.192.51.111 : icmp\_seq=3 ttl=64 temps=0.067 ms 

--- statistiques ping 10.192.51.111 --- 

3 paquets transmis, 3 reçus, 0 % paquets perdus, temps 2025 ms rtt min/moy/max/mdev = 0,064/0,065/0,067/0,001 ms 

Question 13 :

arp ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.008.png)

Adresse                  TypeMap AdresseMat          Indicateurs           Iface 10.192.0.255             ether   00:00:5e:00:01:0a   C                     eno1 vmarm001.univ-lr.fr      ether   6c:2b:59:ea:c4:0e   C                     eno1 silo192.univ-lr.fr       ether   3a:83:99:00:f7:d7   C                     eno1 serverrx.univ-lr.fr      ether   00:1f:29:05:05:ba   C                     eno1 

Je reconnais l'adresse de vmarm001 qui représente la machine virtuelle

Question 14 :

ping -c 2 10.192.51.111 ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.009.png)

PING 10.192.51.111 (10.192.51.111) 56(84) bytes of data. 

64 octets de 10.192.51.111 : icmp\_seq=1 ttl=60 temps=2.70 ms 

64 octets de 10.192.51.111 : icmp\_seq=2 ttl=60 temps=1.87 ms 

--- statistiques ping 10.192.51.111 --- 

2 paquets transmis, 2 reçus, 0 % paquets perdus, temps 1002 ms rtt min/moy/max/mdev = 1,867/2,284/2,702/0,417 ms 

Après un nouveau ARP on voit que l'imprimante communique avec la machine

Adresse                  TypeMap AdresseMat          Indicateurs           Iface 10.192.0.255             ether   00:00:5e:00:01:0a   C                     eno1 impll304.univ-lr.fr      ether   00:10:83:53:e0:e2   C                     eno1 vmarm001.univ-lr.fr      ether   6c:2b:59:ea:c4:0e   C                     eno1 ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.010.png)

silo192.univ-lr.fr       ether   3a:83:99:00:f7:d7   C                     eno1 serverrx.univ-lr.fr      ether   00:1f:29:05:05:ba   C                     eno1 

On retrouve le @MAC de l'imprimante qui est : **00:10:83:53:e0:e2**

Question 15 :

ping -c 2 serverie ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.011.png)

PING serverie.univ-lr.fr (10.192.50.254) 56(84) bytes of data. 

De arm001.univ-lr.fr (10.192.51.111) icmp\_seq=1 Hôte de destination injoignable De arm001.univ-lr.fr (10.192.51.115) icmp\_seq=2 Hôte de destination injoignable 

--- statistiques ping serverie.univ-lr.fr --- 

2 paquets transmis, 0 reçus, +2 erreurs, 100 % paquets perdus, temps 1021 ms  tuyau 2 

On voit que la communication n'a pas pu être faite

arp ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.012.png)

Adresse                  TypeMap AdresseMat          Indicateurs           Iface vmarm001.univ-lr.fr      ether   6c:2b:59:ea:c4:0e   C                     eno1 serverrx.univ-lr.fr      ether   00:1f:29:05:05:ba   C                     eno1 impll304.univ-lr.fr      ether   00:10:83:53:e0:e2   C                     eno1 10.192.0.255             ether   00:00:5e:00:01:0a   C                     eno1 serverie.univ-lr.fr              (incomplet)                               eno1 silo192.univ-lr.fr       ether   3a:83:99:00:f7:d7   C                     eno1 

Donc les informations sur serverie non pas pu être récupérer. Cela peut être parce que cette carte communique pas sur le même tronçon réseau quelque soit le protocole

Question 16 :

Voici les commandes entrées pour comparer la liste avant et après avoir essayez de ping le site *"www.univ- larochelle.fr"* :

tlefranc@u20focal048:~$ arp ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.013.png)

Adresse                  TypeMap AdresseMat          Indicateurs           Iface echide02.univ-lr.fr      ether   90:b1:1c:4a:7f:6a   C                     ens160 pandora.univ-lr.fr       ether   00:50:56:be:40:7c   C                     ens160 qi.univ-lr.fr            ether   00:50:56:be:ca:c8   C                     ens160 echide255.univ-lr.fr     ether   f0:1f:af:df:fa:d7   C                     ens160 

hubusbiut.univ-lr.fr     ether   00:40:9d:89:49:93   C                     ens160 10.2.0.250               ether   24:6e:96:1c:51:d8   C                     ens160 routeur2.univ-lr.fr      ether   00:00:5e:00:01:0a   C                     ens160 bluemind-etudiant.univ-  ether   00:50:56:be:4e:89   C                     ens160 nagios2.univ-lr.fr       ether   00:50:56:be:94:1c   C                     ens160 

tlefranc@u20focal048:~$ ping -c 2 www.univ-larochelle.fr ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.014.png)

PING samsara.univ-lr.fr (193.48.38.46) 56(84) bytes of data. 

64 octets de samsara.univ-lr.fr (193.48.38.46) : icmp\_seq=1 ttl=112 temps=0.365 ms 

64 octets de samsara.univ-lr.fr (193.48.38.46) : icmp\_seq=2 ttl=112 temps=0.438 ms --- statistiques ping samsara.univ-lr.fr --- 

2 paquets transmis, 2 reçus, 0 % paquets perdus, temps 1006 ms 

rtt min/moy/max/mdev = 0,365/0,401/0,438/0,036 ms 

tlefranc@u20focal048:~$ arp ![](Aspose.Words.510df075-9426-433b-bf39-7b90ce524216.015.png)

Adresse                  TypeMap AdresseMat          Indicateurs           Iface echide02.univ-lr.fr      ether   90:b1:1c:4a:7f:6a   C                     ens160 pandora.univ-lr.fr       ether   00:50:56:be:40:7c   C                     ens160 qi.univ-lr.fr            ether   00:50:56:be:ca:c8   C                     ens160 echide255.univ-lr.fr     ether   f0:1f:af:df:fa:d7   C                     ens160 hubusbiut.univ-lr.fr     ether   00:40:9d:89:49:93   C                     ens160 10.2.0.250               ether   24:6e:96:1c:51:d8   C                     ens160 routeur2.univ-lr.fr      ether   00:00:5e:00:01:0a   C                     ens160 bluemind-etudiant.univ-  ether   00:50:56:be:4e:89   C                     ens160 nagios2.univ-lr.fr       ether   00:50:56:be:94:1c   C                     ens160 

On remarque donc que rien n'a été ajouté et je pense que c'est dû à une résolution DNS impossible ce qui fait que l'affichage du FQMN ne peut pas se faire.
6 / 6
