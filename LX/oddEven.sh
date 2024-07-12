#! /bin/bash

read -p "Enter Number: " n

if ((n%2==0))
then
  echo "The number is even."
else
  echo "The number is odd."
fi