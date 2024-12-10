#include "main.h"

Date today(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;
    return Date(day, month, year);
}



int main(){
    // Create an instance of MockDao
    MockDao mockDao;

    // Retrieve proposals from MockDao
    std::vector<std::shared_ptr<Proposal>> proposals = mockDao.getAll();

    // Create an instance of SponsorConsulter with discount percentages
    SponsorConsulter sponsorConsulter;

    // Endorse the proposals
    std::vector<std::shared_ptr<ApprovedProposal>> approvedProposals = sponsorConsulter.endorse(proposals);

    // Process and display the approved proposals
    for (const auto& approvedProposal : approvedProposals) {
        std::shared_ptr<Employee> employee = approvedProposal->getEmployee();
        if (employee == nullptr) {
            continue;
        }
        std::cout << "Approved Proposal: " << employee->name() << std::endl;
        std::cout << "Sponsor Percent: " << approvedProposal->SponsorPercent() << "%" << std::endl;
        // Add more details as needed
    }
    std::cout << "\n\n";

    // Create an instance of ApprovedProposalToTableConverter
    std::vector<std::string> headers = {"ID", "Employee", "Seniority", "Book title", "Original Price", "Sponsor Percent", "Total Amount"};
    std::vector<int> columnSizes = {3, 20, 10, 63, 15, 15, 15};
    std::shared_ptr<ApprovedProposalToTableConverter> converter = std::make_shared<ApprovedProposalToTableConverter>(headers, columnSizes);

    // Convert the approved proposals to a list of objects
    std::vector<std::shared_ptr<Object>> objects;
    for (const auto& approvedProposal : approvedProposals) {
        objects.push_back(std::static_pointer_cast<Object>(approvedProposal));
    }

    // Convert the created objects' list to a table
    std::string table = converter->convertToTable(objects, "Approved Proposals");
    std::cout << table << "\n\n";
    

    return 0;
}