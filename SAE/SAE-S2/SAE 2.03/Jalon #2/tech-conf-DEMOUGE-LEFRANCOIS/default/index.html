<?php
$filename = "counter.txt";
$handle = fopen($filename, "r");
$counter = (int) fread($handle, filesize($filename));
fclose($handle);
$counter++;
$handle = fopen($filename, "w");
fwrite($handle, $counter);
fclose($handle);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Tek-it-Izy - Default Website</title>
    <script>
        function updateClock() {
            var now = new Date();
            if(now.getMinutes() < 10 && now.getSeconds() < 10) {
                var timeString = now.getHours() + ':0' + now.getMinutes() + ':0' + now.getSeconds();
                document.getElementById('time').innerHTML = timeString;
            }
            else if(now.getMinutes() < 10) {
                var timeString = now.getHours() + ':0' + now.getMinutes() + ':' + now.getSeconds();
                document.getElementById('time').innerHTML = timeString;
            }
            else if(now.getSeconds() < 10) {
                var timeString = now.getHours() + ':' + now.getMinutes() + ':0' + now.getSeconds();
                document.getElementById('time').innerHTML = timeString;
            }
            else {
                var timeString = now.getHours() + ':' + now.getMinutes() + ':' + now.getSeconds();
                document.getElementById('time').innerHTML = timeString;
            }     
        }
        setInterval(updateClock, 1000); // actualise toutes les secondes
    </script>
</head>
<body>
    <section class="mainpage">


        <div class="header">
            <img src="https://i.imgur.com/1kzQawr.png" alt="Logo de Tek-it-Izy" class="logo">
            <h1>Tek-it-Izy Server - Default page - <?php echo date('Y-m-d')?> - <span id="time"></span></h1>
        </div>
        
        <div class="paragraph">
            <p>
                <?php echo "This page has been visited " . $counter . " times."; ?>
            </p>
            <p>
                You are currently on the default page of the Apache web server used to host the <a href="http://www.tek-it-izy.org" onclick="event.preventDefault(); window.location.href='http://www.tek-it-izy.org';">"Tek-it-Izy"</a> company sites. <br>
                This site allows the verification of the implementation of this server. 
            </p>
        </div>

        <div class="divider"></div>

        <div class="paragraph">
            <h3>Configuration overview</h3>
            <p>
                The Apache web server runs on a Rapsberry Pi running RPi OS Lite. 
                The configuration of the Apache web server is done by using different configuration files allowing you to adjust the settings of the websites. 
                You can also use PHP and Javascript on the webpages you host on this server.<br> <br>
                Here, you can find a simple overview of the configuration layout of the server:
            </p>
        </div>

        <div class="schema">
            <code>
                /etc/apache2 <br>
                ├── apache2.conf #the main configuration file for Apache, it contains directives for configuring the server as whole<br>
                ├── conf-available <br>
                ├── conf-enabled <br>
                ├── envvars <br>
                ├── magic <br>
                ├── mods-available #contains configuration files for Apache modules that are available but not yet enabled <br>
                ├── mods-enabled #contains configuration files for Apache modules that are enabled <br>
                ├── ports.conf <br>
                ├── sites-available #contains symbolic links to the configuration files of available websites <br>
                ├── sites-enabled #contains symbolic links to the configuration files of enabled websites <br>
                └── ssl <br>
            </code>
        </div>

        <div class="divider"></div>

        <div class="paragraph">
            <h3>Default website <a href="">(raspb244.univ-lr.fr)</a> </h3>
            <p>
                You are currently on the default website of the Apache web server. <br>
                The configuration of this website is located in the <code>/etc/apache2/sites-available/000-default.conf</code> file.
                The main HTML page of this website is located in the <code>/var/www/html</code> directory. <br>
                This website allows users to publish their own pages on the website by placing them in their <code>/public_html</code> folder.
                To acces their pages, the users simply have to go to the <code>raspb244.univ-lr.fr/~username</code> address on a web brower <br>
                
            </p>
        </div>

        <div class="schema">
            <code>
                /var/www/html <br>
                ├── counter.txt <br>
                ├── index.php <br>
                └── style.css <br> <br>

                Exemple of user personnal page: <br>
                /home/username/public_html <br>
                ├── index.html <br>
                └── style.css <br>
            </code>
        </div>

        <div class="divider"></div>

        <div class="paragraph">
            <h3>Public website <a href="http://www.tek-it-izy.org" onclick="event.preventDefault(); window.location.href='http://www.tek-it-izy.org';">(www.tek-it-izy.org)</a></h3>
            <p>
                The public website of the Tek-it-Izy company is a "showcase" website presenting quickly the company and its services. <br>
                The configuration of this website is located in the <code>/etc/apache2/sites-available/site-public.conf</code> file.
                The files of the website are located in the <code>/srv/www/public</code> directory (see on the schema) and the
                website has custom error pages.
            </p>
        </div>

        <div class="schema">
            <code>
                /srv/www <br>
                ├── log <br>
                │   ├── acces <br>
                │   │   └── access.log <br>
                │   └── erreur <br>
                │        └── error.log <br>
                └── public <br>
                     ├── arborescence <br>
                     │   └── youcanseethisfile.txt <br>
                     ├── erreurs <br>
                     │   ├── 401.html <br>
                     │   ├── 403.html <br>
                     │   └── 404.html <br>
                     ├── index.html <br>
                     ├── more-mission.html <br>
                     ├── more-presentation.html <br>
                     ├── styles.css <br>
                     └── testfolder <br>
            </code>
        </div>

        <div class="divider"></div>

        <div class="paragraph">
            <h3>Internal website <a href="http://intranet.tek-it-izy.org" onclick="event.preventDefault(); window.location.href='http://intranet.tek-it-izy.org';">(intranet.tek-it-izy.org)</a></h3>
            <p>
                The internal website of the Tek-it-Izy company is a website used by the employees of the company to share information and documents. <br>
                The configuration of this website is located in the <code>/etc/apache2/sites-available/site-intranet.conf</code> file.
                The files of the website are located in the <code>/srv/intranet</code> directory (see on the schema) and the
                website has custom error pages.
                To connect to the website, the users have to use the right username and password gift by <a href="http://www.tek-it-izy.org" onclick="event.preventDefault(); window.location.href='http://www.tek-it-izy.org';">"Tek-it-Izy"</a>.
            </p>
        </div>

        <div class="schema">
            <code>
                /srv/intranet <br>
                ├── arborescence <br>
                │   └── youcantseethisfile.txt <br>
                ├── erreurs <br>
                │   ├── 401.html <br>
                │   ├── 403.html <br>
                │   └── 404.html <br>
                ├── index.html <br>
                ├── log <br>
                │   ├── acces <br>
                │   │   └── access.log <br>
                │   └── erreur <br>
                │        └── error.log <br>
                └── testfolder <br>
            </code>
        </div>
    </section>
    
</body>
</html>
