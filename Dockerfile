
FROM ros:humble

# Install the packages you need
RUN apt-get update && apt-get install -y \
    ros-humble-demo-nodes-cpp \
    ros-humble-demo-nodes-py \
    && rm -rf /var/lib/apt/lists/*

# Set up the environment
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
