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
 * \author Minsheng Zhang <mzhang4@memphis.edu>
 *
 **/
#ifndef CONF_PROCESSOR_HPP
#define CONF_PROCESSOR_HPP

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/cstdint.hpp>

#include "nlsr.hpp"

namespace nlsr {

class ConfFileProcessor
{
public:
  ConfFileProcessor(Nlsr& nlsr, const std::string& cfile)
    : m_confFileName(cfile)
    , m_nlsr(nlsr)
  {
  }

  bool
  processConfFile();

private:
  bool
  load(std::istream& input);

  bool
  processSection(const std::string& section,
                 boost::property_tree::ptree SectionAttributeTree);

  bool
  processConfSectionGeneral(boost::property_tree::ptree SectionAttributeTree);

  bool
  processConfSectionNeighbors(boost::property_tree::ptree SectionAttributeTree);

  bool
  processConfSectionHyperbolic(boost::property_tree::ptree SectionAttributeTree);

  bool
  processConfSectionFib(boost::property_tree::ptree SectionAttributeTree);

  bool
  processConfSectionAdvertising(boost::property_tree::ptree SectionAttributeTree);

  bool
  processConfSectionSecurity(boost::property_tree::ptree SectionAttributeTree);

private:
  typedef boost::property_tree::ptree ConfigSection;

  std::string m_confFileName;
  Nlsr& m_nlsr;
};

} //namespace nlsr
#endif //CONF_PROCESSOR_HPP
