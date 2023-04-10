/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2008, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Justin Kottinger */

#ifndef OMPL_MULTIROBOT_BASE_PLAN_VALIDITY_CHECKER_
#define OMPL_MULTIROBOT_BASE_PLAN_VALIDITY_CHECKER_

#include "ompl/multirobot/base/Plan.h"
#include "ompl/util/ClassForward.h"

namespace ompl
{
    namespace multirobot
    {
        namespace base
        {
            /// @cond IGNORE
            OMPL_CLASS_FORWARD(SpaceInformation);
            /// @endcond

            /// @cond IGNORE
            /** \brief Forward declaration of ompl::multirobot::base::StateValidityChecker */
            OMPL_CLASS_FORWARD(PlanValidityChecker);
            /// @endcond

            class PlanValidityChecker
            {
            public:
                /** \brief Constructor */
                PlanValidityChecker(const SpaceInformationPtr &si) : si_(si.get())
                {
                }

                /** \brief Return true if the \e plan is valid. Usually, this means at least collision checking. */
                virtual bool isValid(const PlanPtr &plan) const = 0;

            protected:
                /** \brief The instance of space information this state validity checker operates on */
                SpaceInformation *si_;

            };
        }
    }
}

#endif
