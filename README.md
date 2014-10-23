skMatrixElements Maya Plugin
===========================

### Introduction

A simple node that allows users to extract individual elements of a matrix

### Sample use cases

* Get the world translation of any transform node by extracting m30, m31 and m32 of its .worldMatrix and forming a vector out of them using a VectorProduct node

### Usage

1) Load the plugin, either using the Plug-in Manager or using the following MEL command:

If you are using the C++ plugin:

    loadPlugin "skMatrixElements"

If you are using the Python plugin:

    loadPlugin "skScriptedMatrixElements.py"

2) Create the node using the following MEL command:

If you are using the C++ plugin:

    createNode skMatrixElements

If you are using the Python plugin:

    createNode skScriptedMatrixElements

3) Connect any matrix element (e.g. .worldMatrix from any transform) into .inputMatrix

4) Connect any of the 16 float outputs (e.g. m00, m23) to any float inputs

### License

Released under The MIT License (MIT)<br/>
Copyright (c) 2014 Skeel Lee <http://cg.skeelogy.com>
