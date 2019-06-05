#include "SpellBook.h"

SpellBook::SpellBook() {
    debugPrint("SpellBook created");
}
SpellBook::~SpellBook() {
    std::map<std::string, Spell*>::iterator it = book.begin();
    
    for ( ; it != book.end(); it++ ) {
        delete (it->second);
    }
    
    debugPrint("SpellBook destroyed");
}

const std::map<std::string, Spell*>& SpellBook::getBook() const {
    return this->book;
}

void SpellBook::insertSpell(Spell* spell) {
    this->book.insert(std::pair<const std::string, Spell*>(spell->getName(), spell));
    
    debugPrint("Spell inserted into spell book");
}

bool SpellBook::haveSpell(const std::string& name) const{
    std::map<std::string, Spell*>::const_iterator it;
    it = this->book.find(name);
    
    if ( it == book.end() ) {
        std::cout << "Unit don't have " << name << " spell" << std::endl;
        return false;
    }
    
    return true;
}

Spell& SpellBook::getSpell(const std::string& name) const {
    if ( !this->haveSpell(name) ) {
        throw UnitDontHaveSpell();
    }
    
    return *this->book.find(name)->second;
}

std::ostream& operator<<(std::ostream& out, const SpellBook& book) {
    std::map<std::string, Spell*>::const_iterator it;
    it = book.getBook().begin();
    
    if ( book.getBook().empty() ) {
        out << "Spell book is empty" << std::endl;
    } else {
        for ( int i = 1, limit = book.getBook().size(); i < limit; it++, i++ ) {
        out << *it->second << std::endl;
        }
        out << *it->second;
    }
    return out;
}
