################ Création des utilisateurs ############
# Doit créer des utilisateurs à partir de collabo.csv #
#######################################################

#! /bin/bash

############## Mis à jour  #####################
sudo apt update
sudo apt upgrade

############## Création des groupes  #####################
sudo groupadd dev
mkdir /home/dev 
chgrp dev /home/dev
chmod -R 770 /home/dev 

sudo groupadd web
mkdir /home/web
chgrp web /home/web
chmod -R 770 /home/web

sudo groupadd mark
mkdir /home/marketing
chgrp mark /home/marketing
chmod -R 770 /home/marketing

sudo groupadd chefs

############## Création du squelette  #####################
mkdir /etc/skel/Documents
mkdir /etc/skel/Images
mkdir /etc/skel/Téléchargements

############## Création du squelette  #####################
mkdir /home/dev/partagedev
chgrp dev /home/dev/partagedev
chmod -R 770 /home/dev/partagedev

mkdir /home/web/partageweb
chgrp web /home/web/partageweb
chmod -R 770 /home/web/partageweb

mkdir /home/marketing/partagemark
chgrp mark /home/marketing/partagemark
chmod -R 770 /home/marketing/partagemark

mkdir /home/partageChefs
chgrp chefs /home/partageChefs
chmod -R 770 /home/partageChefs

mkdir /home/partageTous
chmod -R 777 /home/partageTous

############## Création des users + Configuration  #####################
while IFS=";" read -r firstname name pswd dpt
do

    letter_user="$(echo $firstname | head -c 1)"

    name_user="$(echo $name | head -c 8)"

    username=`echo ${letter_user}${name_user} | tr '[A-Z]' '[a-z]'`

    group=`echo ${dpt} | tr '[A-Z]' '[a-z]'` 

    if [ "$group" = "mark" ]
    then
            group="marketing"
            useradd -g mark -m -d /home/$group/$username -s /bin/bash $username
    else
            useradd -g $group -m -d /home/$group/$username -s /bin/bash $username
    fi

    sudo echo -e "$pswd\n$pswd" | passwd $username

    ln -s /home/$group/partage$group /home/$group/$username
    
    chown -R $username /home/$group/$username

    chmod -R 700 /home/$group/$username

done < $1 | tail -n +2 #Ne pas prendre la première ligne

#Ajout du groupe chefs pour 3 users
sudo usermod -a -G chefs emusk
sudo usermod -a -G chefs jbezos
sudo usermod -a -G chefs barnault

#Liens spéciaux pour les chefs
ln -s /home/partageChefs /home/dev/emusk
ln -s /home/partageChefs /home/web/jbezos
ln -s /home/partageChefs /home/marketing/barnault



##################### SOFTWARE ########################
#     Doit installer les logiciels et IDE demandés    #
#######################################################

echo #Saut de ligne
echo "##### Scripts Software #########"
echo #Saut de ligne

############ Installation de VS CODE ############
echo "########### Installation de VS CODE ############"
echo #Saut de ligne
sudo apt-get update
sudo apt-get install code -y
echo #Saut de ligne

############ Installation de Firefox ############
echo "########### Installation de Firefox ############"
echo #Saut de ligne 
sudo apt-get update
sudo apt-get install firefox-esr
echo #Saut de ligne

####### Installation de LibreOffice #############
echo "########### Installation de LibreOffice ############"
echo #Saut de ligne
sudo apt-get update
sudo apt-get install libreoffice
echo #Saut de ligne 

##############################################################

echo "############### Fin des installations ###############"
echo #Saut de ligne 
