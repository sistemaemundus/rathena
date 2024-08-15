#!/bin/bash 

while ! mysqladmin ping -h db -u ragnarok --password=ragnarok --silent; do
    echo "Aguardando o MySQL iniciar..."
    sleep 1
done

echo "MySQL está disponível. Iniciando servidores."

./login-server &
./char-server &
./map-server

while [ 1 ]; do
    /bin/bash
done