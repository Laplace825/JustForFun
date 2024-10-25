#!/bin/bash

if [ -d "build" ]; then
    rm -rf ./build/*
    rm -rf ./build/.*
fi
