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
#ifndef CONF_PARAMETER_HPP
#define CONF_PARAMETER_HPP

#include <iostream>
#include <boost/cstdint.hpp>
#include <ndn-cxx/common.hpp>
#include <ndn-cxx/face.hpp>

#include "logger.hpp"

namespace nlsr {

enum {
  LSA_REFRESH_TIME_MIN = 240,
  LSA_REFRESH_TIME_DEFAULT = 1800,
  LSA_REFRESH_TIME_MAX = 7200
};

enum {
  HELLO_RETRIES_MIN = 1,
  HELLO_RETRIES_DEFAULT = 3,
  HELLO_RETRIES_MAX = 15
};

enum {
  HELLO_TIMEOUT_MIN = 1,
  HELLO_TIMEOUT_DEFAULT = 3,
  HELLO_TIMEOUT_MAX = 15
};

enum {
  HELLO_INTERVAL_MIN = 30,
  HELLO_INTERVAL_DEFAULT = 60,
  HELLO_INTERVAL_MAX =90
};

enum {
  MAX_FACES_PER_PREFIX_MIN = 0,
  MAX_FACES_PER_PREFIX_MAX = 60
};

enum {
  HYPERBOLIC_STATE_OFF = 0,
  HYPERBOLIC_STATE_ON = 1,
  HYPERBOLIC_STATE_DRY_RUN = 2
};

class ConfParameter
{

public:
  ConfParameter()
    : m_lsaRefreshTime(LSA_REFRESH_TIME_DEFAULT)
    , m_routerDeadInterval(2*LSA_REFRESH_TIME_DEFAULT)
    , m_logLevel("INFO")
    , m_interestRetryNumber(HELLO_RETRIES_DEFAULT)
    , m_interestResendTime(HELLO_TIMEOUT_DEFAULT)
    , m_infoInterestInterval(HELLO_INTERVAL_DEFAULT)
    , m_hyperbolicState(HYPERBOLIC_STATE_OFF)
    , m_corR(0)
    , m_corTheta(0)
    , m_maxFacesPerPrefix(MAX_FACES_PER_PREFIX_MIN)
  {}

  void
  setNetwork(const ndn::Name& networkName)
  {
    m_network = networkName;
    m_chronosyncPrefix = m_network;
    m_chronosyncPrefix.append("NLSR");
    m_chronosyncPrefix.append("sync");
    
    m_lsaPrefix = m_network;
    m_lsaPrefix.append("NLSR");
    m_lsaPrefix.append("LSA");
  }

  const ndn::Name&
  getNetwork()
  {
    return m_network;
  }

  void
  setRouterName(const ndn::Name& routerName)
  {
    m_routerName = routerName;
  }

  const ndn::Name&
  getRouterName()
  {
    return m_routerName;
  }

  void
  setSiteName(const ndn::Name& siteName)
  {
    m_siteName = siteName;
  }

  const ndn::Name&
  getSiteName()
  {
    return m_siteName;
  }

  void
  buildRouterPrefix()
  {
    m_routerPrefix = m_network;
    m_routerPrefix.append(m_siteName);
    m_routerPrefix.append(m_routerName);
  }

  const ndn::Name&
  getRouterPrefix()
  {
    return m_routerPrefix;
  }


  const ndn::Name&
  getChronosyncPrefix()
  {
    return m_chronosyncPrefix;
  }

  const ndn::Name&
  getLsaPrefix()
  {
    return m_lsaPrefix;
  }

  void
  setLsaRefreshTime(int32_t lrt)
  {
    m_lsaRefreshTime = lrt;
    m_routerDeadInterval = 2 * m_lsaRefreshTime;
  }

  int32_t
  getLsaRefreshTime()
  {
    return m_lsaRefreshTime;
  }

  void
  setRouterDeadInterval(int64_t rdt)
  {
    m_routerDeadInterval = rdt;
  }

  int64_t
  getRouterDeadInterval()
  {
    return m_routerDeadInterval;
  }
  
  void 
  setLogLevel(const std::string& logLevel)
  {
    m_logLevel = logLevel;
  }
  
  const std::string& 
  getLogLevel()
  {
    return m_logLevel;
  }

  void
  setInterestRetryNumber(uint32_t irn)
  {
    m_interestRetryNumber = irn;
  }

  uint32_t
  getInterestRetryNumber()
  {
    return m_interestRetryNumber;
  }

  void
  setInterestResendTime(int32_t irt)
  {
    m_interestResendTime = irt;
  }

  int32_t
  getInterestResendTime()
  {
    return m_interestResendTime;
  }

  int32_t
  getInfoInterestInterval()
  {
    return m_infoInterestInterval;
  }

  void
  setInfoInterestInterval(int32_t iii)
  {
    m_infoInterestInterval = iii;
  }

  void
  setHyperbolicState(int32_t ihc)
  {
    m_hyperbolicState = ihc;
  }

  int32_t
  getHyperbolicState()
  {
    return m_hyperbolicState;
  }

  bool
  setCorR(double cr)
  {
    if ( cr >= 0 ) {
     m_corR = cr;
     return true;
    }
    return false;
  }

  double
  getCorR()
  {
    return m_corR;
  }

  void
  setCorTheta(double ct)
  {
    m_corTheta = ct;
  }

  double
  getCorTheta()
  {
    return m_corTheta;
  }
  
  void
  setMaxFacesPerPrefix(int32_t mfpp)
  {
    m_maxFacesPerPrefix = mfpp;
  }

  int32_t
  getMaxFacesPerPrefix()
  {
    return m_maxFacesPerPrefix;
  }

  void
  setLogDir(const std::string& logDir)
  {
    m_logDir = logDir;
  }

  const std::string&
  getLogDir()
  {
    return m_logDir;
  }

  void
  setSeqFileDir(const std::string& ssfd)
  {
    m_seqFileDir = ssfd;
  }

  const std::string&
  getSeqFileDir()
  {
    return m_seqFileDir;
  }

  void
  writeLog();

private:
  ndn::Name m_routerName;
  ndn::Name m_siteName;
  ndn::Name m_network;

  ndn::Name m_routerPrefix;
  ndn::Name m_lsaRouterPrefix;

  ndn::Name m_chronosyncPrefix;
  ndn::Name m_lsaPrefix;

  int32_t  m_lsaRefreshTime;
  int64_t  m_routerDeadInterval;
  std::string m_logLevel;

  uint32_t m_interestRetryNumber;
  int32_t  m_interestResendTime;
  
  
  int32_t  m_infoInterestInterval;
  
  int32_t m_hyperbolicState;
  double m_corR;
  double m_corTheta;

  int32_t m_maxFacesPerPrefix;
  
  std::string m_logDir;
  std::string m_seqFileDir;

};

} // namespace nlsr

#endif //CONF_PARAMETER_HPP
