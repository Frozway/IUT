
<html>
         <head>
                <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
                <title>Page perso de Thibaut LEFRANCOIS</title>
        </head>
        <body>
                
                <h1>Compte Rendu du TP2 </h1>
                <p>Thibaut LEFRANCOIS D2 </p>

                <h1> Réponses aux questions </h1>

                <h2><u>Question 1 : </u> </h2>
                <p>
                Un serveur Web est un ordinateur qui héberge des sites Web et les rend accessibles en ligne via le protocole HTTP. <br>
                Les utilisateurs peuvent accéder à un site Web en entrant son URL dans leur navigateur, ce qui envoie une demande au serveur qui renvoie alors les données du site. <br>
                Les serveurs peuvent être déployés sur une variété de systèmes d'exploitation, y compris Windows, Linux et macOS.<br><br>
                Sources :
                    <ul>
                            <li>https://fr.wikipedia.org/wiki/Serveur_web</li>
                            <li>https://www.techopedia.com/definition/34899/web-server</li>
                            <li>https://www.guru99.com/what-is-web-server.html</li>
                    </ul>
                </p>

                <h2><u> Question 2 : </u> </h2>
                <p>
                SSH (Secure Shell) est un protocole de communication de réseau sécurisé utilisé pour se connecter à un ordinateur distant et exécuter des commandes sur celui-ci. <br>
                Il permet également de transférer des fichiers de manière sécurisée entre les ordinateurs. SSH est largement utilisé pour la gestion des serveurs distants et la configuration du réseau. <br><br>
                Sources :
                    <ul>
                            <li>https://fr.wikipedia.org/wiki/Serveur_web</li>
                            <li>https://www.techopedia.com/definition/34899/web-server</li>
                            <li>https://www.guru99.com/what-is-web-server.html</li>
                    </ul>
                </p>

                <h2><u> Question 3 : </u> </h2>
                <h3>Informations sur la machine virtuelle</h3>
                <p>Adresse IP : 10.2.157.216</p>
                <p>Nom : u20focal046</p>
                        
                <h3>Informations sur la machine physique</h3>
                <p>Adresse IP : 10.192.51.14</p>
                <p>Nom : sparc04.univ-lr.fr</p>
                        
                <h3>Commande de connexion en ssh</h3>
        <pre><code>
        ssh tlefranc@ovh3.univ-lr.fr
        </code></pre>

                <h2><u> Question 4 : </u></h2>

                <p>Le dernier chiffre dans les permissions d'un répertoire tel que "755" représente les permissions pour le propriétaire du répertoire. Le 7 autorise la lecture, l'écriture et l'exécution. Le 5 autorisé la lecture et l'exécution, mais pas l'écriture.</p>

                <p> Le dernier chiffre dans les permissions d'un fichier tel que "644" représente les permissions pour le propriétaire du fichier. Le 6 autorise la lecture et l'écriture, mais pas l'exécution. Le 4 autorise seulement la lecture et pas l'écriture ni l'exécution. </p>
       
                <p> En utilisant la commande ls -l j'ai pu vérifier que tous les répertoires traversés jusqu'à mon fichier index.html ont les droits 755 et que le fichier lui-même à les droits 644.</p>

                <h2><u> Question 5 : </u></h2>

                <p>L'url qui permet d'accéder à ma page personnel sur le serveur est : <b><u>http://ovh3.univ-lr.fr/~tlefranc</u></b> </p>

                <a href="http://ovh3.univ-lr.fr/~tlefranc">Lien vers page perso de Thibaut LEFRANCOIS sur ovh3</a>

                <h2><u> Question 6 : </u></h2>

                <p>
                File Transfer Protocol (FTP) est un protocole de communication qui permet de transférer des fichiers entre un ordinateur local et un ordinateur distant sur un réseau. <br>
                FTP utilise une connexion client-serveur pour envoyer et recevoir des fichiers. Il est généralement utilisé pour héberger et télécharger des fichiers en ligne, notamment des sites web, des images, des vidéos et des fichiers de musique. <br><br>      
                Sources :
                    <ul>
                            <li>https://fr.wikipedia.org/wiki/Serveur_web</li>
                            <li>https://www.techopedia.com/definition/34899/web-server</li>
                            <li>https://www.guru99.com/what-is-web-server.html</li>
                    </ul>
                </p>

                <h2><u> Question 7 : </u></h2>

                <pre>
        $ sftp d303pc18@serverRX 
        d303pc18@serverrx's password: (webmaster)
        Connected to serverRX.
        sftp> 
                </pre>

                <h2><u> Question 8 : </u></h2>

                <p>Sortie terminal pour vérifier le répertoire distant avec la commande pwd : (ls montre bien que c'est vide)</p>
                <pre>/home/d303pc18</pre>          
                <p>Commande pour modifier les droits du répertoire distant en 755 avec la commande chmod :</p>
                <pre>chmod 755 /home/d303pc18</pre>
                <p>Commande pour créer un répertoire nommé public_html et attribuer les droits 755 :</p>
                <pre>mkdir public_html && chmod 755 public_html</pre>
                <p> <b> !pwd </b> nous renvoie : <b> /home/admin </b> </p>

                <h2><u> Question 9 : </u></h2>

                <p> On utilise la commande <b>put index.html</b> une fois bien positionné en local pour transférer le fichier sur le répertoire distant public_html </p>
                <p> On voit que le fichier n'a pas les bons droits et on utilise alors chmod tel que : <b>chmod 644 index.html</b> sur le serveur distant</p>
                <p>L'URL pour accéder à notre page  index.html depuis notre machine physique est <b>"serverrx.univ-lr.fr/~d303pc18"</b></p>

		<h2><u> Question 10 : </u></h2>
		
		<p> Date : </p>

		<?php echo date('D, j/n/Y H:i:s'); ?>

</html>

