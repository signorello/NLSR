/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014  University of Memphis,
 *                     Regents of the University of California
 *
 * This file is part of NLSR (Named-data Link State Routing).
 * See AUTHORS.md for complete list of NLSR authors and contributors.
 *
 * NLSR is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NLSR is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NLSR, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \author A K M Mahmudul Hoque <ahoque1@memphis.edu>
 *
 **/
#ifndef NLSR_NEXTHOP_HPP
#define NLSR_NEXTHOP_HPP

#include <iostream>
#include <boost/cstdint.hpp>

namespace nlsr {
class NextHop
{
public:
  NextHop()
    : m_connectingFaceUri()
    , m_routeCost(0)
  {
  }

  NextHop(const std::string& cfu, double rc)
  {
    m_connectingFaceUri = cfu;
    m_routeCost = rc;
  }

  const std::string&
  getConnectingFaceUri() const
  {
    return m_connectingFaceUri;
  }

  void
  setConnectingFaceUri(const std::string& cfu)
  {
    m_connectingFaceUri = cfu;
  }

  double
  getRouteCost() const
  {
    return m_routeCost;
  }

  void
  setRouteCost(double rc)
  {
    m_routeCost = rc;
  }

private:
  std::string m_connectingFaceUri;
  double m_routeCost;
};

}//namespace nlsr

#endif //NLSR_NEXTHOP_HPP
