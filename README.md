# DEV4 - Abalone

## Introduction

- Remise 1 : Modélisation Logicielle 19/02/21 18:00
- Remise 2 : Implémentation métier avec interface console 2/04/21 18:00
- Remise 3 : Interface graphique 7/05/21 18:00

## Régles

> - Grille hexagonale de 5x5x5 soit 61 hexagone
> - 14 billes de chaque couleur
> - Sans opposition, se déplace dans 6 directions
> - Deux déplcament en _ligne_ et en _côté_
> - Déplcament de groupe de bille de 1 à 3 max de même couleur
> - Prioriré numerique peux pousser les billes adverse

### Analyse

![Analyse Abalone](screenshot.png)

#### Remise

> Remise 1

`git commit -a -m "modelization release"`
`git tag -a modelization -m "modelization release"`
`git push --follow-tags`

> Remise 2

`git commit -a -m "console release"`
`git tag -a modelization -m "console release"`
`git push --follow-tags`

> Remise 3

`git commit -a -m "gui release"`
`git tag -a modelization -m "gui release"`
`git push --follow-tags`
