/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer

=========================================================================auto=*/

#ifndef __vtkMRMLIGTLSessionManagerNode_h
#define __vtkMRMLIGTLSessionManagerNode_h

// MRML includes
#include "vtkMRMLNode.h"
#include "vtkSlicerBRPProstateNavModuleMRMLExport.h"

class vtkIGTLToMRMLString;

/// \brief MRML node to manage OpenIGTLink 
///
/// Configure vtkMRMLIGTLConnectorNode and manage incoming and outgoing
/// data during a OpenIGTLink session.
class VTK_SLICER_BRPPROSTATENAV_MODULE_MRML_EXPORT vtkMRMLIGTLSessionManagerNode : public vtkMRMLNode
{
public:
  static vtkMRMLIGTLSessionManagerNode *New();

  vtkTypeMacro(vtkMRMLIGTLSessionManagerNode,vtkMRMLNode);

  void PrintSelf(ostream& os, vtkIndent indent);

  virtual vtkMRMLNode* CreateNodeInstance();

  /// 
  /// Read node attributes from XML file
  virtual void ReadXMLAttributes( const char** atts);

  /// 
  /// Write this node's information to a MRML file in XML format.
  virtual void WriteXML(ostream& of, int indent);

  /// 
  /// Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() {return "IGTLSessionManager";};

  ///
  /// Set and configure MRMLIGTLconnector node
  void SetAndObserveConnectorNodeID(const char *connectorNodeID);

  ///
  /// Set a reference to transform node
  void AddAndObserveMessageNodeID(const char *transformNodeID);

  /// 
  /// Associated transform MRML node
  //vtkMRMLTransformNode* GetParentTransformNode();

  /// 
  /// alternative method to propagate events generated in Transform nodes
  virtual void ProcessMRMLEvents ( vtkObject * /*caller*/, 
                                  unsigned long /*event*/, 
                                  void * /*callData*/ );

  //BTX
  virtual void OnNodeReferenceAdded(vtkMRMLNodeReference *reference);

  virtual void OnNodeReferenceRemoved(vtkMRMLNodeReference *reference);

  virtual void OnNodeReferenceModified(vtkMRMLNodeReference *reference);
  //ETX

  enum
    {
      TransformModifiedEvent = 15000
    };

  /// Get referenced connector node id
  const char *GetConnectorNodeID();

protected:
  vtkMRMLIGTLSessionManagerNode();
  ~vtkMRMLIGTLSessionManagerNode();
  vtkMRMLIGTLSessionManagerNode(const vtkMRMLIGTLSessionManagerNode&);
  void operator=(const vtkMRMLIGTLSessionManagerNode&);

  //----------------------------------------------------------------
  // Reference role strings
  //----------------------------------------------------------------
  char* ConnectorNodeReferenceRole;
  char* ConnectorNodeReferenceMRMLAttributeName;

  vtkSetStringMacro(ConnectorNodeReferenceRole);
  vtkGetStringMacro(ConnectorNodeReferenceRole);

  vtkSetStringMacro(ConnectorNodeReferenceMRMLAttributeName);
  vtkGetStringMacro(ConnectorNodeReferenceMRMLAttributeName);

  char* MessageNodeReferenceRole;
  char* MessageNodeReferenceMRMLAttributeName;

  vtkSetStringMacro(MessageNodeReferenceRole);
  vtkGetStringMacro(MessageNodeReferenceRole);

  vtkSetStringMacro(MessageNodeReferenceMRMLAttributeName);
  vtkGetStringMacro(MessageNodeReferenceMRMLAttributeName);


private:
  char* ConnectorNodeIDInternal;
  vtkSetStringMacro(ConnectorNodeIDInternal);
  vtkGetStringMacro(ConnectorNodeIDInternal);

  vtkIGTLToMRMLString * StringMessageConverter;

};

#endif
