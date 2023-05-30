##################### Script Users ####################
# Doit créer des utilisateurs à partir de collabo.csv #
#######################################################

#! /bin/bash

############## Création des groupes  #####################
sudo groupadd dev
mkdir /home/dev 

sudo groupadd web
mkdir /home/web

sudo groupadd mark
mkdir /home/marketing

############## Création du squelette  #####################
mkdir /etc/skel/Documents
mkdir /etc/skel/Images
mkdir /etc/skel/Téléchargements

############## Création du squelette  #####################
mkdir /home/dev/partagedev
mkdir /home/web/partageweb
mkdir /home/marketing/partagemark
mkdir /home/partageChefs
mkdir /home/partageTous

############## Création des users + Configuration  #####################
while IFS=";" read -r firstname name pswd dpt
do

    letter_user="$(echo $firstname | head -c 1)"

    name_user="$(echo $name | head -c 8)"

    username=`echo ${letter_user}${name_user} | tr '[A-Z]' '[a-z]'`

    group=`echo ${dpt} | tr '[A-Z]' '[a-z]'` 

    useradd -g $group -m -d /home/$group/$username $username

    sudo echo -e "$pswd\n$pswd" | passwd $username
    
    chown -R $username /home/$group/$username

done < $1 | tail -n +2 #Ne pas prendre la première ligne
