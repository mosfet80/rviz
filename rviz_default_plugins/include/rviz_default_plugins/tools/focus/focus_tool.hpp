// Copyright (c) 2013, Willow Garage, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the copyright holder nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


#ifndef RVIZ_DEFAULT_PLUGINS__TOOLS__FOCUS__FOCUS_TOOL_HPP_
#define RVIZ_DEFAULT_PLUGINS__TOOLS__FOCUS__FOCUS_TOOL_HPP_

#include <QCursor>

#include "rviz_common/tool.hpp"
#include "rviz_common/viewport_mouse_event.hpp"

#include "rviz_default_plugins/visibility_control.hpp"

namespace rviz_default_plugins
{
namespace tools
{

//! The Focus Tool allows the user to set the focal point of the current
//! view controller with a single mouse click.
class RVIZ_DEFAULT_PLUGINS_PUBLIC FocusTool : public rviz_common::Tool
{
public:
  FocusTool();
  ~FocusTool() override;

  void onInitialize() override;

  void activate() override;
  void deactivate() override;

  int processMouseEvent(rviz_common::ViewportMouseEvent & event) override;

private:
  void computePositionForDirection(
    const rviz_common::ViewportMouseEvent & event, Ogre::Vector3 & position);

  void setStatusFrom(const Ogre::Vector3 & position);

protected:
  QCursor std_cursor_;
  QCursor hit_cursor_;
};

}  // namespace tools
}  // namespace rviz_default_plugins

#endif  // RVIZ_DEFAULT_PLUGINS__TOOLS__FOCUS__FOCUS_TOOL_HPP_
