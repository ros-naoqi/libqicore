/**
* @author Aldebaran Robotics
* Aldebaran Robotics (c) 2012 All Rights Reserved
*/

#pragma once

#ifndef FLOWDIAGRAM_P_H_
#define FLOWDIAGRAM_P_H_

# include <qicore-compat/model/linkmodel.hpp>
# include <qicore-compat/model/boxinstancemodel.hpp>

namespace qi {
 class FlowDiagramModelPrivate
 {
   friend class FlowDiagramModel;
 public:
   FlowDiagramModelPrivate(const std::string &path,
                      float scale,
                      const std::string &formatVersion,
                      const std::list<LinkModelPtr> &links,
                      const std::list<BoxInstanceModelPtr> &boxsInstance);

   bool loadFromFile();

 private:
   std::string _path;
   float _scale;
   std::string _formatVersion;
   std::list<LinkModelPtr> _links;
   std::list<BoxInstanceModelPtr> _boxsInstance;
 };
}

#endif /* !FLOWDIAGRAM_P_H_ */