#!/bin/bash

cd docker
docker build -t benishor/scad .
cd ..
docker run -d --rm -v $(pwd):/work/project benishor/scad
