/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 17.12
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HTEXTUREINSPECTIONMODEL
#define HCPP_HTEXTUREINSPECTIONMODEL

namespace HalconCpp
{

// Represents an instance of a texture model for texture inspection.
class LIntExport HTextureInspectionModel : public HToolBase
{

public:

  // Create an uninitialized instance
  HTextureInspectionModel():HToolBase() {}

  // Copy constructor
  HTextureInspectionModel(const HTextureInspectionModel& source) : HToolBase(source) {}

  // Create HTextureInspectionModel from handle, taking ownership
  explicit HTextureInspectionModel(Hlong handle);

  // Set new handle, taking ownership
  void SetHandle(Hlong handle);

  // Deep copy of all data represented by this object instance
  HTextureInspectionModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_texture_inspection_model: Create a texture inspection model.
  explicit HTextureInspectionModel(const HString& ModelType);

  // create_texture_inspection_model: Create a texture inspection model.
  explicit HTextureInspectionModel(const char* ModelType);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Add training images to the texture inspection model.
  HTuple AddTextureInspectionModelImage(const HImage& Image) const;

  // Inspection of the texture within an image.
  HRegion ApplyTextureInspectionModel(const HImage& Image, HTextureInspectionResult* TextureInspectionResultID) const;

  // Create a texture inspection model.
  void CreateTextureInspectionModel(const HString& ModelType);

  // Create a texture inspection model.
  void CreateTextureInspectionModel(const char* ModelType);

  // Deserialize a serialized texture inspection model.
  void DeserializeTextureInspectionModel(const HSerializedItem& SerializedItemHandle);

  // Get the training images contained in a texture inspection model.
  HImage GetTextureInspectionModelImage() const;

  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const HTuple& GenParamName) const;

  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const HString& GenParamName) const;

  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const char* GenParamName) const;

  // Read a texture inspection model from a file.
  void ReadTextureInspectionModel(const HString& FileName);

  // Read a texture inspection model from a file.
  void ReadTextureInspectionModel(const char* FileName);

  // Clear all or a user-defined subset of the images of a texture inspection model.
  static HTuple RemoveTextureInspectionModelImage(const HTextureInspectionModelArray& TextureInspectionModel, const HTuple& Indices);

  // Clear all or a user-defined subset of the images of a texture inspection model.
  HTuple RemoveTextureInspectionModelImage(const HTuple& Indices) const;

  // Serialize a texture inspection model.
  HSerializedItem SerializeTextureInspectionModel() const;

  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const HString& GenParamName, Hlong GenParamValue) const;

  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const char* GenParamName, Hlong GenParamValue) const;

  // Train a texture inspection model.
  void TrainTextureInspectionModel() const;

  // Write a texture inspection model to a file.
  void WriteTextureInspectionModel(const HString& FileName) const;

  // Write a texture inspection model to a file.
  void WriteTextureInspectionModel(const char* FileName) const;

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HToolArrayRef;

typedef HToolArrayRef<HTextureInspectionModel> HTextureInspectionModelArrayRef;
typedef HSmartPtr< HTextureInspectionModelArrayRef > HTextureInspectionModelArrayPtr;


// Represents multiple tool instances
class LIntExport HTextureInspectionModelArray : public HToolArray
{

public:

  // Create empty array
  HTextureInspectionModelArray();

  // Create array from native array of tool instances
  HTextureInspectionModelArray(HTextureInspectionModel* classes, Hlong length);

  // Copy constructor
  HTextureInspectionModelArray(const HTextureInspectionModelArray &tool_array);

  // Destructor
  virtual ~HTextureInspectionModelArray();

  // Assignment operator
  HTextureInspectionModelArray &operator=(const HTextureInspectionModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HTextureInspectionModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HTextureInspectionModelArrayPtr *mArrayPtr;
};

}

#endif
