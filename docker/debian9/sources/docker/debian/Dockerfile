# Set the base image using miniconda 
FROM amd64/debian

RUN apt-get update && apt-get install -y
RUN apt-get upgrade -y
RUN apt-get install gcc -y
RUN apt-get install vim -y
RUN apt-get install procps -y

# Set working directory 
#WORKDIR /home/projectC