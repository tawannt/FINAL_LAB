#include "ApprovedProposalToTableConverter.h"

ApprovedProposalToTableConverter::ApprovedProposalToTableConverter() {
    _headers = std::vector<std::string>();
    _columnSizes = std::vector<int>();
}

ApprovedProposalToTableConverter::ApprovedProposalToTableConverter(std::vector<std::string>& headers, std::vector<int>& columnSizes) {
    _headers = headers;
    _columnSizes = columnSizes;
}

std::string ApprovedProposalToTableConverter::convertToTable(std::vector<std::shared_ptr<Object>>& os, std::string intro) {
    std::stringstream table;

    // create header
    table << "|";
    for (size_t i = 0; i < _headers.size(); ++i) {
        table << std::setw(_columnSizes[i]) << std::right << _headers[i] << "|";
    }
    table << "\n";



    // add --------
    int sizeTable = 0;
    sizeTable += 5;
    for(int i = 0; i < _columnSizes.size(); i++){
        sizeTable += _columnSizes[i];
    }
    table << std::setw(sizeTable) << std::setfill('-') << "-" << "\n";

    float totalSponsorAmount = 0;
    for (int i = 0; i < os.size(); i++){
        std::stringstream builder_id;
        builder_id << "|" << std::setw(_columnSizes[0]) << std::right << i + 1;
        table << builder_id.str();

        ApprovedProposalToTableConverter::ApprovedProposalToRowConverter rowConverter(_columnSizes); 
        std::string appProRow = rowConverter.convert(os[i]);
        table << appProRow << "\n";

        std::shared_ptr<ApprovedProposal> appPro = std::dynamic_pointer_cast<ApprovedProposal> (os[i]);
        totalSponsorAmount += appPro->SponsorAmount();
    }
    CurrencyFormatter dollar;
    table << "\nTotal Sponsor Amount: " << dollar.format(totalSponsorAmount) << "\n\n";

    return table.str();
}

std::string ApprovedProposalToTableConverter::convert(Object& object) {
    // empty implementation
    return "";
}

std::string ApprovedProposalToTableConverter::toString() {
    return "ApprovedProposalToTableConverter";
}

ApprovedProposalToTableConverter::ApprovedProposalToRowConverter::ApprovedProposalToRowConverter(std::vector<int>& columnSizes) {
    _columnSizes = columnSizes;
}

std::string ApprovedProposalToTableConverter::ApprovedProposalToRowConverter::convert(std::shared_ptr<Object>& o) const {
    std::shared_ptr<ApprovedProposal> appPro = std::dynamic_pointer_cast<ApprovedProposal>(o);
    std::stringstream builder;

    // get employee name
    std::shared_ptr<Employee> employee = appPro->getEmployee();
    builder << "|" << std::setw(_columnSizes[1]) << std::left << employee->name();

    // get seniority
    SeniorityEnum seniority = SeniorityClassifier().classify(*employee);
    // convert seniority to string
    SeniorityToStringConverter seniorityConverter;
    std::string seniorityStr = seniorityConverter.convertToString(seniority);
    builder << "|" << std::setw(_columnSizes[2]) << std::left << seniorityStr;

    // get book title, price, sponsor percent, final amount
    CurrencyFormatter dollar;
    std::shared_ptr<Book> book = appPro->getBook();
    builder << "|" << std::setw(_columnSizes[3]) << std::left << book->title();
    // convert price to string
    std::string price = dollar.format(book->price());
    builder << "|" << std::setw(_columnSizes[4]) << std::left << price;
    // convert sponsor percent to string and add '%'
    stringstream sponsorPercent;
    sponsorPercent << std::setprecision(4) << appPro->SponsorPercent();
    sponsorPercent << "%";
    builder << "|" << std::setw(_columnSizes[5]) << std::left << sponsorPercent.str();

    // calculate final amount
    float finalAmount = book->price() - appPro->SponsorAmount();
    std::string finalAmountStr = dollar.format(finalAmount);
    builder << "|" << std::setw(_columnSizes[6]) << std::left << finalAmountStr;

    return builder.str();
}

