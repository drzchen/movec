################################################################################
# This file is used to build a Docker image for artifact evaluation.
# Please install Docker and then build the image in this directory:
#   $ sudo docker build -t movec:latest .
# When the image is built, you can run it:
#   $ sudo docker run -it -v [a-host-directory]:/home/export movec
# Note that you need to specify a host directory to export data (using -v).
# The artifact and generated data are at /home/artifact in the container.
# You may copy the generated data to /home/export in the container, and then
# you can review the data at the host directory on your host system.
################################################################################

# Build on Ubuntu
FROM ubuntu:22.04
MAINTAINER Anonymous

# Install software
RUN apt-get update && \
    apt-get install -y time && \
    apt-get install -y gcc g++ make && \
    apt-get install -y libncurses5-dev && \
    apt-get install -y bear

# Copy files
ENV ARTIFACT_HOME /home/artifact
ENV PATH $ARTIFACT_HOME/bin:$PATH
ADD benchmarks-memsafe $ARTIFACT_HOME/benchmarks-memsafe
ADD bin                $ARTIFACT_HOME/bin
ADD examples           $ARTIFACT_HOME/examples
ADD LICENSE.txt README.md $ARTIFACT_HOME
WORKDIR $ARTIFACT_HOME

# Set environment
CMD /bin/bash
