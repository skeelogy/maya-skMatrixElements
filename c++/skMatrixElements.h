/*
 * Author: Skeel Lee
 * Contact: skeel@skeelogy.com
 * Since: 23 Oct 2014
 *
 * A simple node that allows users to extract individual elements of a matrix
 *
 * ---------Usage-------------
 *
 * 1) Load the plugin, either using the Plug-in Manager or using the following
 * MEL command:
 *
 *     loadPlugin "skMatrixElements"
 *
 * 2) Create the node using the following MEL command:
 *
 *     createNode skMatrixElements
 *
 * 3) Connect any matrix element (e.g. .worldMatrix from any transform) into
 * .inputMatrix
 *
 * 4) Connect any of the output floats to any float inputs
 *
 * ---------Sample Use Cases-------------
 *
 * - Get the world translation of any transform node by extracting m30, m31
 *   and m32 of its .worldMatrix and forming a vector out of them using a
 *   VectorProduct node
 *
 * ---------License-------------
 *
 * Released under The MIT License (MIT) Copyright (c) 2014 Skeel Lee
 * (http://cg.skeelogy.com)
 */

#ifndef _SK_MATRIX_ELEMENTS_H_
#define _SK_MATRIX_ELEMENTS_H_

class SkMatrixElements : public MPxNode
{

public:
    SkMatrixElements() {}
    virtual ~SkMatrixElements() {}
    virtual MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
    static void* creator();
    static MStatus initialize();

public:
    static MTypeId nodeId;
    static MObject inputMatrix;
    static MObject m00;
    static MObject m01;
    static MObject m02;
    static MObject m03;
    static MObject m10;
    static MObject m11;
    static MObject m12;
    static MObject m13;
    static MObject m20;
    static MObject m21;
    static MObject m22;
    static MObject m23;
    static MObject m30;
    static MObject m31;
    static MObject m32;
    static MObject m33;

};

#endif
