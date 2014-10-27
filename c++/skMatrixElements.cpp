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

#include <maya/MFnPlugin.h>
#include <maya/MTypeId.h>
#include <maya/MGlobal.h>

#include <maya/MPxNode.h>

#include <maya/MFnNumericAttribute.h>
#include <maya/MFnNumericData.h>
#include <maya/MFnMatrixAttribute.h>

#include <maya/MMatrix.h>

#include "skMatrixElements.h"

MString nodeType("skMatrixElements");
MString nodeVersion("1.0");
MTypeId SkMatrixElements::nodeId(0x001212C4); //unique id obtained from ADN

#define CHECK_ERROR(stat, msg) \
    if (!stat) { \
        MString errorMsg("[" + nodeType + "] " + __FILE__ + " " + __LINE__ + ": " msg); \
        MGlobal::displayError(errorMsg); \
        cerr << errorMsg << endl; \
        return MS::kFailure; \
    }

MObject SkMatrixElements::inputMatrix;
MObject SkMatrixElements::m00;
MObject SkMatrixElements::m01;
MObject SkMatrixElements::m02;
MObject SkMatrixElements::m03;
MObject SkMatrixElements::m10;
MObject SkMatrixElements::m11;
MObject SkMatrixElements::m12;
MObject SkMatrixElements::m13;
MObject SkMatrixElements::m20;
MObject SkMatrixElements::m21;
MObject SkMatrixElements::m22;
MObject SkMatrixElements::m23;
MObject SkMatrixElements::m30;
MObject SkMatrixElements::m31;
MObject SkMatrixElements::m32;
MObject SkMatrixElements::m33;

//main compute method
MStatus SkMatrixElements::compute(const MPlug& plug, MDataBlock& dataBlock)
{
    MStatus stat = MS::kSuccess;

    if (plug == SkMatrixElements::m00)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m00, &stat);
        CHECK_ERROR(stat, "Unable to get m00 data handle\n");
        outputHandle.setFloat(inputMatrix(0,0));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m01)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m01, &stat);
        CHECK_ERROR(stat, "Unable to get m01 data handle\n");
        outputHandle.setFloat(inputMatrix(0,1));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m02)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m02, &stat);
        CHECK_ERROR(stat, "Unable to get m02 data handle\n");
        outputHandle.setFloat(inputMatrix(0,2));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m03)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m03, &stat);
        CHECK_ERROR(stat, "Unable to get m03 data handle\n");
        outputHandle.setFloat(inputMatrix(0,3));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m10)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m10, &stat);
        CHECK_ERROR(stat, "Unable to get m10 data handle\n");
        outputHandle.setFloat(inputMatrix(1,0));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m11)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m11, &stat);
        CHECK_ERROR(stat, "Unable to get m11 data handle\n");
        outputHandle.setFloat(inputMatrix(1,1));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m12)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m12, &stat);
        CHECK_ERROR(stat, "Unable to get m12 data handle\n");
        outputHandle.setFloat(inputMatrix(1,2));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m13)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m13, &stat);
        CHECK_ERROR(stat, "Unable to get m13 data handle\n");
        outputHandle.setFloat(inputMatrix(1,3));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m20)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m20, &stat);
        CHECK_ERROR(stat, "Unable to get m20 data handle\n");
        outputHandle.setFloat(inputMatrix(2,0));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m21)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m21, &stat);
        CHECK_ERROR(stat, "Unable to get m21 data handle\n");
        outputHandle.setFloat(inputMatrix(2,1));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m22)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m22, &stat);
        CHECK_ERROR(stat, "Unable to get m22 data handle\n");
        outputHandle.setFloat(inputMatrix(2,2));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m23)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m23, &stat);
        CHECK_ERROR(stat, "Unable to get m23 data handle\n");
        outputHandle.setFloat(inputMatrix(2,3));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m30)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m30, &stat);
        CHECK_ERROR(stat, "Unable to get m30 data handle\n");
        outputHandle.setFloat(inputMatrix(3,0));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m31)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m31, &stat);
        CHECK_ERROR(stat, "Unable to get m31 data handle\n");
        outputHandle.setFloat(inputMatrix(3,1));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m32)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m32, &stat);
        CHECK_ERROR(stat, "Unable to get m32 data handle\n");
        outputHandle.setFloat(inputMatrix(3,2));
        dataBlock.setClean(plug);
    }
    else if (plug == SkMatrixElements::m33)
    {
        MDataHandle dataHandle = dataBlock.inputValue(SkMatrixElements::inputMatrix, &stat);
        CHECK_ERROR(stat, "Unable to get inputMatrix data handle\n");
        MMatrix inputMatrix = dataHandle.asMatrix();
        MDataHandle outputHandle = dataBlock.outputValue(SkMatrixElements::m33, &stat);
        CHECK_ERROR(stat, "Unable to get m33 data handle\n");
        outputHandle.setFloat(inputMatrix(3,3));
        dataBlock.setClean(plug);
    }
    else
    {
        stat = MS::kUnknownParameter;
    }

    return stat;
}

//creator method
void* SkMatrixElements::creator()
{
    return new SkMatrixElements();
}

//init method
MStatus SkMatrixElements::initialize()
{
    MStatus stat = MS::kSuccess;

    MFnNumericAttribute nAttr;
    MFnMatrixAttribute mAttr;

    //inputMatrix attr
    inputMatrix = mAttr.create("inputMatrix", "im", MFnMatrixAttribute::kDouble, &stat);
    CHECK_ERROR(stat, "Unable to create inputMatrix attribute\n");
    stat = addAttribute(inputMatrix);
    CHECK_ERROR(stat, "Unable to add inputMatrix attribute\n");

    //m00 attr
    m00 = nAttr.create("m00", "m00", MFnNumericData::kFloat, 1.0, &stat);
    CHECK_ERROR(stat, "Unable to create m00 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m00);
    CHECK_ERROR(stat, "Unable to add m00 attribute\n");

    //m01 attr
    m01 = nAttr.create("m01", "m01", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m01 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m01);
    CHECK_ERROR(stat, "Unable to add m01 attribute\n");

    //m02 attr
    m02 = nAttr.create("m02", "m02", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m02 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m02);
    CHECK_ERROR(stat, "Unable to add m02 attribute\n");

    //m03 attr
    m03 = nAttr.create("m03", "m03", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m03 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m03);
    CHECK_ERROR(stat, "Unable to add m03 attribute\n");

    //m10 attr
    m10 = nAttr.create("m10", "m10", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m10 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m10);
    CHECK_ERROR(stat, "Unable to add m10 attribute\n");

    //m11 attr
    m11 = nAttr.create("m11", "m11", MFnNumericData::kFloat, 1.0, &stat);
    CHECK_ERROR(stat, "Unable to create m11 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m11);
    CHECK_ERROR(stat, "Unable to add m11 attribute\n");

    //m12 attr
    m12 = nAttr.create("m12", "m12", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m12 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m12);
    CHECK_ERROR(stat, "Unable to add m12 attribute\n");

    //m13 attr
    m13 = nAttr.create("m13", "m13", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m13 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m13);
    CHECK_ERROR(stat, "Unable to add m13 attribute\n");

    //m20 attr
    m20 = nAttr.create("m20", "m20", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m20 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m20);
    CHECK_ERROR(stat, "Unable to add m20 attribute\n");

    //m21 attr
    m21 = nAttr.create("m21", "m21", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m21 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m21);
    CHECK_ERROR(stat, "Unable to add m21 attribute\n");

    //m22 attr
    m22 = nAttr.create("m22", "m22", MFnNumericData::kFloat, 1.0, &stat);
    CHECK_ERROR(stat, "Unable to create m22 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m22);
    CHECK_ERROR(stat, "Unable to add m22 attribute\n");

    //m23 attr
    m23 = nAttr.create("m23", "m23", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m23 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m23);
    CHECK_ERROR(stat, "Unable to add m23 attribute\n");

    //m30 attr
    m30 = nAttr.create("m30", "m30", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m30 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m30);
    CHECK_ERROR(stat, "Unable to add m30 attribute\n");

    //m31 attr
    m31 = nAttr.create("m31", "m31", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m31 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m31);
    CHECK_ERROR(stat, "Unable to add m31 attribute\n");

    //m32 attr
    m32 = nAttr.create("m32", "m32", MFnNumericData::kFloat, 0.0, &stat);
    CHECK_ERROR(stat, "Unable to create m32 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m32);
    CHECK_ERROR(stat, "Unable to add m32 attribute\n");

    //m33 attr
    m33 = nAttr.create("m33", "m33", MFnNumericData::kFloat, 1.0, &stat);
    CHECK_ERROR(stat, "Unable to create m33 attribute\n");
    nAttr.setStorable(false);
    stat = addAttribute(m33);
    CHECK_ERROR(stat, "Unable to add m33 attribute\n");

    //connect attrs
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m00);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m00");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m01);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m01");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m02);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m02");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m03);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m03");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m10);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m10");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m11);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m11");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m12);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m12");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m13);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m13");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m20);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m20");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m21);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m21");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m22);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m22");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m23);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m23");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m30);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m30");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m31);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m31");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m32);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m32");
    stat = attributeAffects(SkMatrixElements::inputMatrix, SkMatrixElements::m33);
    CHECK_ERROR(stat, "Unable to call attributeAffects from inputMatrix to m33");

    return stat;
}

//init plugin
MStatus initializePlugin(MObject obj)
{
    MStatus stat;
    MFnPlugin plugin(obj, "Skeel Lee", nodeVersion.asChar(), "Any");
    stat = plugin.registerNode(nodeType, SkMatrixElements::nodeId, SkMatrixElements::creator, SkMatrixElements::initialize);
    CHECK_ERROR(stat, "Failed to register node: " + nodeType + "\n")
    return stat;
}

//uninit plugin
MStatus uninitializePlugin(MObject obj)
{
    MStatus stat;
    MFnPlugin plugin(obj);
    stat = plugin.deregisterNode(SkMatrixElements::nodeId);
    CHECK_ERROR(stat, "Failed to register node: " + nodeType + "\n")
    return stat;
}
