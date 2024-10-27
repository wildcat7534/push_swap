#!/bin/bash

# Définir les valeurs MIN_INT et MAX_INT
# MIN_INT=-2147483648
# MAX_INT=2147483647
MIN_INT=-1000
MAX_INT=1000

# Vérifier si un argument est passé
if [ -z "$1" ]; then
  echo "Usage: $0 <nombre de valeurs (3, 10000)>"
  exit 1
fi

# Vérifier si l'argument est un nombre valide
if ! [[ "$1" =~ ^[0-9]+$ ]] || [ "$1" -lt 3 ] || [ "$1" -gt 10000 ]; then
  echo "Erreur: Choisissez entre 3 10000 nombres."
  exit 1
fi

# Générer les nombres aléatoires sans doublons
export ARG1=$(seq $MIN_INT $MAX_INT | shuf -n "$1" | tr '\n' ' ')

# Afficher les nombres générés
echo "$ARG1"
# *******************************************************************************
# Vérifier si l'argument "push" est fourni
if [ "$2" == "push" ]; then
  # Chercher ./push_swap dans le répertoire courant ou parent
  if [ -x "./push_swap" ]; then
    echo "Exécution de ./push_swap depuis le répertoire courant..."
    ./push_swap $ARG1
  elif [ -x "../push_swap" ]; then
    echo "Exécution de ../push_swap depuis le répertoire parent..."
    ../push_swap $ARG1
  else
    echo "Erreur: ./push_swap introuvable dans le répertoire courant ou parent."
    exit 1
  fi
fi
