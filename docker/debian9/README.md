# Quickstart Docker

### L'environnement

1. Monter le docker
```
docker-compose build
```

2. Up Docker
```
docker-compose up -d
```

# Containers DEBIAN

### lancer le script Debian9
```
docker exec -it DEBIAN bin/bash
```
or 
```
docker run -it amd64/debian bin/bash 
```

# Autre commandes dockers

### Lister les conteneurs
```
docker ps
```
### Arrêter tous les conteneurs
```
docker stop $(docker ps -q)
```

### Supprimer tous les conteneurs
```
docker rm $(docker ps -a -q)
```

### Cette commande peut être combinée avec celle d'arrêt pour arrêter et supprimer tous les conteneurs :
```
docker stop $(docker ps -a -q) && docker rm $(docker ps -a -q)
```
### Supprimer tout les images
```
sudo docker rmi $(docker images -q)
```

