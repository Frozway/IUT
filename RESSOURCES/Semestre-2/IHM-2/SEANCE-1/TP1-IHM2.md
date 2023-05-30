#TP - Première application graphique

>Thibaut LEFRANCOIS D2 
>09/03/2023 

---

##  1) Fabrication d’une première application graphique

**1.** *Donnez le lien, dans la documentation officielle, décrivant la méthode add utilisée par l’objet "gLayout".*

Voici le lien dans la documentation officielle, décrivant la méthode add utilisée par l’objet gLayout : `https://doc.qt.io/qt-6/qwidget.html`

Ici une briève description de la méthode add : `void QGridLayout::addWidget(QWidget *widget, int row, int column, Qt::Alignment alignment = Qt::Alignment())    `

Ajoute le widget donné à la grille de cellules à row , column . La position en haut à gauche est (0, 0) par défaut.

L'alignement est spécifié par alignement . L'alignement par défaut est 0, ce qui signifie que le widget remplit toute la cellule.

---

**2.** *En vous aidant de la documentation, expliquez ce que fait l’instruction suivante : gLayout->addWidget(button, 2, 1);*

Dans ce programme, l'instruction suivante est utilisée pour *
*ajouter un bouton (QPushButton) à un layout (QGridLayout)** avec les coordonnées spécifiées : gLayout->addWidget(button, 2, 1).

 Pour être plus précis, l'instruction gLayout->addWidget(button, 2, 1); ajoute l'objet button de type QPushButton créé sur la ligne précédente au layout gLayout avec les arguments suivants :

* Le premier argument (button) est l'objet à ajouter au layout.
* Le deuxième argument (2) est l'index de la ligne dans le layout où l'objet doit être placé. Dans ce cas, le bouton sera placé à la deuxième ligne.
* Le troisième argument (1) est l'index de la colonne dans le layout où l'objet doit être placé. Dans ce cas, le bouton sera placé à la première colonne.

En résumé le bouton sera ajouté en tant qu'élément de l'interface graphique de l'application. Lorsque l'utilisateur cliquera sur ce bouton, cela déclenchera l'exécution de la fonction lambda connectée au signal clicked du bouton, qui affichera un message de salutation avec le nom saisi dans le champ de texte.

---

**3.** * *
