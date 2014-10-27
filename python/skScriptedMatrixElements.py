"""
@author: Skeel Lee
@contact: skeel@skeelogy.com
@since: 18 Oct 2014

A simple node that allows users to extract individual elements of a matrix

---------Usage-------------

1) Load the plugin, either using the Plug-in Manager or using the following
MEL command:

    loadPlugin "skScriptedMatrixElements.py"

2) Create the node using the following MEL command:

    createNode skScriptedMatrixElements

3) Connect any matrix element (e.g. .worldMatrix from any transform) into
.inputMatrix

4) Connect any of the output floats to any float inputs

---------Sample Use Cases-------------

* Get the world translation of any transform node by extracting m30, m31 and
  m32 of its .worldMatrix and forming a vector out of them using a VectorProduct
  node

---------License-------------

Released under The MIT License (MIT) Copyright (c) 2014 Skeel Lee
(http://cg.skeelogy.com)

"""

import sys

import maya.OpenMaya as om
import maya.OpenMayaMPx as omMPx

nodeType = 'skScriptedMatrixElements'
nodeVersion = '1.0'
nodeId = om.MTypeId(0x001212C3) #unique id obtained from ADN

class SkScriptedMatrixElements(omMPx.MPxNode):

    inputMatrix = om.MObject()
    m00 = om.MObject()
    m01 = om.MObject()
    m02 = om.MObject()
    m03 = om.MObject()
    m10 = om.MObject()
    m11 = om.MObject()
    m12 = om.MObject()
    m13 = om.MObject()
    m20 = om.MObject()
    m21 = om.MObject()
    m22 = om.MObject()
    m23 = om.MObject()
    m30 = om.MObject()
    m31 = om.MObject()
    m32 = om.MObject()
    m33 = om.MObject()

    def __init__(self):
        super(SkScriptedMatrixElements, self).__init__()

    def compute(self, plug, dataBlock):

        if (plug == SkScriptedMatrixElements.m00):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m00)
            outputHandle.setFloat(inputMatrix(0,0))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m01):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m01)
            outputHandle.setFloat(inputMatrix(0,1))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m02):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m02)
            outputHandle.setFloat(inputMatrix(0,2))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m03):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m03)
            outputHandle.setFloat(inputMatrix(0,3))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m10):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m10)
            outputHandle.setFloat(inputMatrix(1,0))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m11):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m11)
            outputHandle.setFloat(inputMatrix(1,1))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m12):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m12)
            outputHandle.setFloat(inputMatrix(1,2))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m13):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m13)
            outputHandle.setFloat(inputMatrix(1,3))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m20):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m20)
            outputHandle.setFloat(inputMatrix(2,0))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m21):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m21)
            outputHandle.setFloat(inputMatrix(2,1))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m22):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m22)
            outputHandle.setFloat(inputMatrix(2,2))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m23):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m23)
            outputHandle.setFloat(inputMatrix(2,3))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m30):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m30)
            outputHandle.setFloat(inputMatrix(3,0))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m31):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m31)
            outputHandle.setFloat(inputMatrix(3,1))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m32):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m32)
            outputHandle.setFloat(inputMatrix(3,2))
            dataBlock.setClean(plug)

        elif (plug == SkScriptedMatrixElements.m33):

            dataHandle = dataBlock.inputValue(SkScriptedMatrixElements.inputMatrix)
            inputMatrix = dataHandle.asMatrix()
            outputHandle = dataBlock.outputValue(SkScriptedMatrixElements.m33)
            outputHandle.setFloat(inputMatrix(3,3))
            dataBlock.setClean(plug)

#creator function
def nodeCreator():
    return omMPx.asMPxPtr(SkScriptedMatrixElements())

#init function
def nodeInitializer():

	#inputMatrix attr
    mAttr = om.MFnMatrixAttribute()
    SkScriptedMatrixElements.inputMatrix = mAttr.create('inputMatrix', 'im')
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.inputMatrix)

    #m00 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m00 = nAttr.create('m00', 'm00', om.MFnNumericData.kFloat, 1.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m00)

    #m01 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m01 = nAttr.create('m01', 'm01', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m01)

    #m02 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m02 = nAttr.create('m02', 'm02', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m02)

    #m03 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m03 = nAttr.create('m03', 'm03', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m03)

    #m10 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m10 = nAttr.create('m10', 'm10', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m10)

    #m11 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m11 = nAttr.create('m11', 'm11', om.MFnNumericData.kFloat, 1.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m11)

    #m12 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m12 = nAttr.create('m12', 'm12', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m12)

    #m13 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m13 = nAttr.create('m13', 'm13', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m13)

    #m20 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m20 = nAttr.create('m20', 'm20', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m20)

    #m21 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m21 = nAttr.create('m21', 'm21', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m21)

    #m22 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m22 = nAttr.create('m22', 'm22', om.MFnNumericData.kFloat, 1.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m22)

    #m23 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m23 = nAttr.create('m23', 'm23', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m23)

    #m30 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m30 = nAttr.create('m30', 'm30', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m30)

    #m31 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m31 = nAttr.create('m31', 'm31', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m31)

    #m32 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m32 = nAttr.create('m32', 'm32', om.MFnNumericData.kFloat, 0.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m32)

    #m33 attr
    nAttr = om.MFnNumericAttribute()
    SkScriptedMatrixElements.m33 = nAttr.create('m33', 'm33', om.MFnNumericData.kFloat, 1.0)
    nAttr.setStorable(False)
    SkScriptedMatrixElements.addAttribute(SkScriptedMatrixElements.m33)

    #connect attrs
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m00)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m01)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m02)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m03)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m10)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m11)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m12)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m13)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m20)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m21)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m22)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m23)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m30)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m31)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m32)
    SkScriptedMatrixElements.attributeAffects(SkScriptedMatrixElements.inputMatrix, SkScriptedMatrixElements.m33)

#init plugin
def initializePlugin(mObject):
    mPlugin = omMPx.MFnPlugin(mObject, "Skeel Lee", nodeVersion, "Any")
    try:
        mPlugin.registerNode(nodeType, nodeId, nodeCreator, nodeInitializer)
    except:
        sys.stderr.write('Failed to register node: %s\n' % (nodeType))
        raise

#uninit plugin
def uninitializePlugin(mObject):
    mPlugin = omMPx.MFnPlugin(mObject)
    try:
        mPlugin.deregisterNode(nodeId)
    except:
        sys.stderr.write('Failed to deregister node: %s\n' % (nodeType))
        raise
