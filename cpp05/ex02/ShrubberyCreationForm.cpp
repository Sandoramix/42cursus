#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Constructor]:\t" << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
	: AForm("ShrubberyCreationForm", 145, 137), target(s.target)
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][CopyConstructor]:\t" << *this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << "[DBG-LOG]\t[" << typeid(this).name() << "][Destructor]:\t\t" << *this << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	if (this == &s)
	{
		return *this;
	}
	this->target = s.target;
	return *this;
}

static const int TREES_COUNT = 5;
static const std::string TREES[TREES_COUNT] = {
	"     ccee88oo\n"
	"  C8O8O8Q8PoOb o8oo\n"
	" dOB69QO8PdUOpugoO9bD\n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\\\//  /douUP\n"
	"        \\\\\\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\....",
	"    oxoxoo    ooxoo\n"
	"  ooxoxo oo  oxoxooo\n"
	" oooo xxoxoo ooo ooox\n"
	" oxo o oxoxo  xoxxoxo\n"
	"  oxo xooxoooo o ooo\n"
	"    ooo\\oo\\  /o/o\n"
	"        \\  \\/ /\n"
	"         |   /\n"
	"         |  |\n"
	"         | D|\n"
	"         |  |\n"
	"         |  |\n"
	"  ______/____\\____",
	"          &&& &&  & &&\n"
	"      && &\\/&\\|& ()|/ @, &&\n"
	"      &\\/(/&/&||/& /_/)_&/_&\n"
	"   &() &\\/&|()|/&\\/ '%\" & ()\n"
	"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
	"&&   && & &| &| /& & % ()& /&&\n"
	" ()&_---()&\\&\\|&&-&&--%---()~\n"
	"     &&     \\|||\n"
	"             |||\n"
	"             |||\n"
	"             |||\n"
	"       , -=-~  .-^- _",
	"                                                         .\n"
	"                                              .         ;  \n"
	"                 .              .              ;%     ;;   \n"
	"                   ,           ,                :;%  %;   \n"
	"                    :         ;                   :;%;'     .,   \n"
	"           ,.        %;     %;            ;        %;'    ,;\n"
	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
	"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"                `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                    `:%;.  :;bd%;          %;@%;'\n"
	"                      `@%:.  :;%.         ;@@%;'   \n"
	"                        `@%.  `;@%.      ;@@%;         \n"
	"                          `@%%. `@%%    ;@@%;        \n"
	"                            ;@%. :@%%  %@@%;       \n"
	"                              %@bd%%%bd%%:;     \n"
	"                                #@%%%%%:;;\n"
	"                                %@@%%%::;\n"
	"                                %@@@%(o);  . '         \n"
	"                                %@@@o%;:(.,'         \n"
	"                            `.. %@@@o%::;         \n"
	"                               `)@@@o%::;         \n"
	"                                %@@(o)::;        \n"
	"                               .%@@@@%::;         \n"
	"                               ;%@@@@%::;.          \n"
	"                              ;%@@@@%%:;;;. \n"
	"                          ...;%@@@@@%%:;;;;,..",
	"              _{\\ _{\\{\\/}/}/}__\n"
	"             {/{/\\}{/{/\\}(\\}{/\\} _\n"
	"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
	"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
	"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
	"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
	"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
	"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
	"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
	"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
	"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
	"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
	"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
	"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
	"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
	"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
	"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
	"              {){/ {\\/}{\\/} \\}\\}\n"
	"              (_)  \\.-'.-/\n"
	"          __...--- |'-.-'| --...__\n"
	"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
	" -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
	" .  '-  '    .--'  | '-.'|    .  '  . '\n"
	"          ' ..     |'-_.-|\n"
	"  .  '  .       _.-|-._ -|-._  .  '  .\n"
	"              .'   |'- .-|   '.\n"
	"  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
	"   .-' '        '-._______.-'     '  .\n"
	"        .      ~,\n"
	"    .       .   |\\   .    ' '-.\n"
	"    ___________/  \\____________\n"
	"   /  Why is it, when you want \\\n"
	"  |  something, it is so damn   |\n"
	"  |    much work to get it?     |\n"
	"   \\___________________________/",
};

void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	AForm::validateRequiredGradeToExecuteOrThrow(b);
	const int idx = rand() % (TREES_COUNT);
	std::string filename = this->target + "_shrubbery";

	std::ofstream outputFile;
	outputFile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!outputFile || outputFile.fail())
	{
		std::cerr << "Error occurred while trying to open the file " << filename << std::endl;
		return;
	}
	outputFile << TREES[idx];
	outputFile.close();
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return target;
}

void ShrubberyCreationForm::setTarget(const std::string &target)
{
	ShrubberyCreationForm::target = target;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &f)
{
	os << "ShrubberyCreationForm(name=" << f.getName()
	   << "; signed=" << (f.getIsSigned() ? "true" : "false")
	   << "; target=" << f.getTarget()
	   << "; requiredGrades{'sign': " << f.getRequiredGradeToSign()
	   << ", 'execute': " << f.getRequiredGradeToExecute() << "})";
	return os;
}
