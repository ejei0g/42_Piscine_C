#!/usr/bin/env bash
echo $FT_NBR1 + $FT_NBR2 | sed 'y/mrdoc/01234/' | sed "y/'\\\"?!/01234/" | xargs echo "obase=13;ibase=5;" |bc | sed 'y/0123456789ABC/gtaio luSnemf/'
