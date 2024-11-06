#!/bin/bash


# Définir les valeurs MIN_INT et MAX_INT
MIN_INT=-1000
MAX_INT=1000

# Fonction pour afficher un message coloré
function echo_colored() {
  echo -e "\033[1;35m$1\033[0m"
}
function echo_colored2() {
  echo -e "\033[1;36m$1\033[0m"
}
function echo_colored3() {
  echo -e "\033[1;33m$1\033[0m"
}
function echo_colored4() {
  echo -e "\033[1;32m$1\033[0m"
}
function echo_colored5() {
  echo -e "\033[1;31m$1\033[0m"
}
function echo_colored6() {
  echo -e "\033[1;34m$1\033[0m"
}
function echo_colored7() {
  echo -e "\033[1;37m$1\033[0m"
}

# Salut a l'utilisateur en recupérant son nom

username=$(whoami)

echo ""
echo ""
echo_colored2 "		      	==============================			"
echo_colored3 "	   	   	      🌟Salut $username🌟				            "
echo_colored2 "		      	==============================			"
echo ""
# Vérifier si un argument est passé
if [ -z "$1" ]; then
  echo ""
  echo_colored5 "Usage: $0 <nombre de valeurs (3 à 10000)> (optinnal pour lancer push_swap : 'push')"
  echo_colored4 "Exemple: $0 100 push"
  echo ""
  exit 1
fi

# Vérifier si l'argument est un nombre valide
if ! [[ "$1" =~ ^[0-9]+$ ]] || [ "$1" -lt 3 ] || [ "$1" -gt 10000 ]; then
  echo_colored5 "Erreur: Choisissez un nombre entre 3 et 10000."
  exit 1
fi
NUM=$1
# Générer les nombres aléatoires sans doublons
echo_colored4 " 🎲  Génération de nombres aléatoires entre $MIN_INT et $MAX_INT..."
echo ""
export ARG2=$(seq $MIN_INT $MAX_INT | shuf -n "$NUM" | tr '\n' ' ')

# Afficher les nombres générés
echo ""
echo_colored4 " 🔢  Nombres générés : "
echo_colored5 "	\$ARG2 = "; echo_colored4 " $ARG2"
echo ""

function execute_push_swap {
  #regeneration de nombres aléatoires
  local ARG3=$(seq $MIN_INT $MAX_INT | shuf -n "$NUM" | tr '\n' ' ')
  ./push_swap "$ARG3" > temp_output.txt
  EXIT_CODE=$?
  MOVE_COUNT=$(wc -l < temp_output.txt)
  echo_colored3 " 📊 Essai pour $NUM nombres : $MOVE_COUNT mouvements"
  rm temp_output.txt
  return $EXIT_CODE
}

# *******************************************************************************
# Vérifier si l'argument "push" est fourni
if [ "$2" == "push" ]; then
  # Chercher ./push_swap dans le répertoire courant ou parent
echo ""
echo_colored " 🚀  Recherche et exécution de ./push_swap..."
echo ""
  if [ -x "./push_swap" ]; then
    echo_colored7 " $>Exécution de ./push_swap depuis le répertoire courant..."
    echo ""
    # Exécuter push_swap 10 fois pour obtenir la moyenne
    ./push_swap $ARG2 > temp_output.txt
    EXIT_CODE=$?  # Capturer le code de retour
    # Nettoyer le fichier temporaire
    rm temp_output.txt
  elif [ -x "../push_swap" ]; then
    echo_colored7 " ../Exécution de ../push_swap depuis le répertoire parent..."
    echo ""
    ../push_swap $ARG2 > temp_output.txt
    EXIT_CODE=$?  # Capturer le code de retour
  else
    echo_colored5 " ❌ Erreur: ./push_swap introuvable dans le répertoire courant ou parent."
    exit 1
  fi
NUM_EXECUTIONS=${NUM_EXECUTIONS:-10}  # Par défaut 10, peut être modifié en argument
# Exécution de push_swap plusieurs fois
i=0
total_moves=0
while [ $i -lt $NUM_EXECUTIONS ]; do
  #echo "Execution $((i+1))"
  execute_push_swap
  total_moves=$((total_moves + MOVE_COUNT))
  ((i++))
done
# Compter le nombre de lignes dans le fichier de sortie
#MOVE_COUNT=$(wc -l < temp_output.txt)

# Afficher le code de retour et le nombre de mouvements
echo_colored6 " ✅  Code de retour de push_swap : $EXIT_CODE"
#echo_colored3 " 📊  Nombre de mouvements exécutés : $MOVE_COUNT"

# proposer de rajouter 'push' en argument
elif [ "$2" == "" ]; then
  echo_colored3 " 🚀   🌟 Tu peux ajouter 'push' pour lancer push_swap automatiquement " 
  echo_colored4 " 🚀      --> Exemple: $0 100 push <--"
  echo ""
  exit 1
fi

function check_sorted() {
  # Vérifier si les nombres sont triés
  if [ "$1" == "push" ]; then
  echo ""
	echo_colored " 🚀  Recherche et exécution de ./checker..."
	./push_swap $ARG2 | ./checker_linux $ARG2 >> temp_output.txt
  else
  echo ""
	echo_colored " 🚀  Recherche et exécution de ./checker..."
	./checker_linux $ARG2 >> temp_output.txt
  fi
  #afficher le contenu du fichier temporaire en couleur et centrer
  echo ""
  # Afficher le résultat de checker en rouge si 'KO' et en vert si 'OK'
  if grep -q "KO" temp_output.txt; then
    echo_colored5 " ❌  Résultat de checker : $(cat temp_output.txt ) !"
  elif grep -q "OK" temp_output.txt; then
    echo_colored4 " ✅  Résultat de checker : $(cat temp_output.txt ) !"
  else
    echo_colored5 " ❌  Error du checker (verifier qu'il y a que les instructions de printf) !"
  fi
  echo ""
  EXIT_CODE=$?  # Capturer le code de retour
  # Nettoyer le fichier temporaire
  rm temp_output.txt
}

# Chercher ./checker dans le répertoire courant ou parent
if [ -x "./checker_linux" ]; then
  check_sorted $2
elif [ -x "../checker_linux" ]; then
  check_sorted $2
else
  echo_colored5 " ❌ Erreur: ./checker introuvable dans le répertoire courant ou parent."
  exit 1
fi

echo ""
echo_colored2 "		====================================================			"
echo_colored3 "		🎉       Merci 🌟 d'avoir utilisé le script !    🎉"
echo_colored2 "		====================================================			"
echo ""

echo_colored "===================================================================================================================="
echo ""
