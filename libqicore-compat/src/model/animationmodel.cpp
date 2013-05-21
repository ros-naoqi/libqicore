/**
* @author Aldebaran Robotics
* Aldebaran Robotics (c) 2012 All Rights Reserved
*/

#include <alserial/alserial.h>
#include <boost/filesystem.hpp>

#include <qicore-compat/model/animationmodel.hpp>
#include "animationmodel_p.hpp"

#include <qi/log.hpp>
qiLogCategory("QiCore-Compat.AnimationModel");

namespace qi
{
  //-------------------------Private Class--------------------------------//

  AnimationModelPrivate::AnimationModelPrivate(const std::string &path,
                                               int fps,
                                               int startFrame,
                                               int endFrame,
                                               int size,
                                               const std::string &formatVersion,
                                               ActuatorListModelPtr actuatorList) :
    _path(path),
    _fps(fps),
    _startFrame(startFrame),
    _endFrame(endFrame),
    _size(size),
    _formatVersion(formatVersion),
    _actuatorList(actuatorList)
  {
  }

  bool AnimationModelPrivate::loadFromFile()
  {
    std::string errorMsg;
    boost::shared_ptr<AL::XmlDocument> xmlFile = AL::XmlDocument::loadFromXmlFile(_path,
                                                                                  NULL,
                                                                                  &errorMsg);

    if(!xmlFile)
    {
      qiLogError() << "Failed to open the given file : "
                   << _path
                   << std::endl
                   << errorMsg
                   << std::endl;
      return false;
    }

    boost::shared_ptr<const AL::XmlElement> root = xmlFile->root();

    if(root == NULL)
    {
      qiLogError() << "No root element in the given file : "
                   << _path
                   << std::endl;
      return false;
    }

    root->getAttribute("fps",            _fps);
    root->getAttribute("start_frame",    _startFrame);
    root->getAttribute("end_frame",      _endFrame);
    root->getAttribute("size",           _size);
    root->getAttribute("format_version", _formatVersion);

    AL::XmlElement::CList actuator_list = root->children("ActuatorList", "");

    if( actuator_list.size() != 1 )
    {
      qiLogError() << "Exactly one tag \"ActuatorList\" is required in file : "
                   << _path
                   << std::endl;
      return false;
    }

    _actuatorList = ActuatorListModelPtr(new ActuatorListModel(actuator_list.front()));

    return _actuatorList->isValid();
  }

  AnimationModel::AnimationModel(const std::string &path,
                                 int fps,
                                 int startFrame,
                                 int endFrame,
                                 int size,
                                 const std::string &formatVersion,
                                 ActuatorListModelPtr actuatorList) :
    _p(new AnimationModelPrivate(path, fps, startFrame, endFrame, size, formatVersion, actuatorList))
  {
  }

  AnimationModel::~AnimationModel()
  {
    delete _p;
  }

  std::string AnimationModel::getPath() const
  {
    boost::filesystem::path path(_p->_path);
    return path.filename().string();
  }

  int AnimationModel::getFPS() const
  {
    return _p->_fps;
  }

  int AnimationModel::getStartFrame() const
  {
    return _p->_startFrame;
  }

  int AnimationModel::getEndFrame() const
  {
    return _p->_endFrame;
  }

  int AnimationModel::getSize() const
  {
    return _p->_size;
  }

  const std::string& AnimationModel::getFormatVersion() const
  {
    return _p->_formatVersion;
  }

  ActuatorListModelPtr AnimationModel::getActuatorList() const
  {
    return _p->_actuatorList;
  }

  void AnimationModel::setPath(const std::string &path)
  {
    _p->_path = path;
  }

  void AnimationModel::setFPS(int fps)
  {
    _p->_fps = fps;
  }

  void AnimationModel::setStartFrame(int start_frame)
  {
    _p->_startFrame = start_frame;
  }

  void AnimationModel::setEndFrame(int end_frame)
  {
    _p->_endFrame = end_frame;
  }

  void AnimationModel::setSize(int size)
  {
    _p->_size = size;
  }

  void AnimationModel::setFormatVersion(const std::string &format_version)
  {
    _p->_formatVersion = format_version;
  }

  void AnimationModel::setActuatorList(ActuatorListModelPtr actuator_list)
  {
    _p->_actuatorList = actuator_list;
  }

  bool AnimationModel::loadFromFile()
  {
    return _p->loadFromFile();
  }
}