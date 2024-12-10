#include "SponsorConsulter.h"

std::vector<std::shared_ptr<ApprovedProposal>> SponsorConsulter::endorse(std::vector<std::shared_ptr<Proposal>> proposals) {
    // create a list of approved proposals
    std::vector<std::shared_ptr<ApprovedProposal>> approvedProposals;

    // config sponsor percent for each seniority
    float fresherSponsorPercentn = 30.0f;
    float juniorSponsorPercent = 50.0f;
    float seniorSponsorPercent = 100.0f;

    for (auto proposal : proposals) {
        // classify seniority
        std::shared_ptr<Employee> employee = proposal->getEmployee();
        SeniorityEnum seniority = SeniorityClassifier().classify(*employee);

        // get sponsor percent
        float sponsorPercent = 0.0;
        if (seniority == Fresher) {
            sponsorPercent = fresherSponsorPercentn;
        } else if (seniority == Junior) {
            sponsorPercent = juniorSponsorPercent;
        } else if (seniority == Senior) {
            sponsorPercent = seniorSponsorPercent;
        }

        // calculate sponsor amount
        std::shared_ptr<Book> originalBook = proposal->getBook();
        float sponsorAmount = originalBook->price() * sponsorPercent / 100;

        // make a new ApprovedProposal
        auto approvedProposal = std::make_shared<ApprovedProposal>(originalBook->price(), sponsorPercent, sponsorAmount);
        approvedProposal->setEmployee(employee);
        approvedProposal->setBook(originalBook);

        // add to the list
        approvedProposals.push_back(approvedProposal);
        
    }
    return approvedProposals;
}

