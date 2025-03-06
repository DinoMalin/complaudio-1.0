#!/bin/bash

python -m venv env
source env/bin/activate

pip install --upgrade pip
pip install dotenv
pip install azure-cognitiveservices-speech
