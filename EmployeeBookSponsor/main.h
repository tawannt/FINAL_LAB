#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <ctime>

#include "./models/Object.h"
#include "./models/Date.h"
#include "./models/Employee.h"
#include "./models/Book.h"
#include "./models/Proposal.h"

#include "./services/business/IParsable.h"
#include "./services/business/ParserFactory.h"
#include "./services/business/EmployeeParser.h"
#include "./services/business/BookParser.h"
#include "./services/business/ProposalParser.h"
#include "./services/business/SeniorityClassifier.h"
#include "./services/business/SponsorConsulter.h"

#include "./services/data-access/IDao.h"
#include "./services/data-access/MockDao.h"
//#include "./services/data-access/RealDao.h"

#include "./services/ui/IConverter.h"
#include "./services/ui/ApprovedProposalToTableConverter.h"
#include "./services/ui/CurrencyFormatter.h"



#endif // MAIN_H