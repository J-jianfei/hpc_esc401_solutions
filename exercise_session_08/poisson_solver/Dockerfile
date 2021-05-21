FROM ubuntu:trusty
RUN apt update
RUN sudo apt install -y g++
RUN sudo apt install -y make 

COPY . /poisson	
RUN cd /poisson 
RUN make
WORKDIR /poisson

CMD . /main