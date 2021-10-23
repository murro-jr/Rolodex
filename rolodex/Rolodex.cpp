//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include "Rolodex.h"

Rolodex::Rolodex()
{
    // Add code here
    sentinel = new RodolexItem;
    sentinel -> next_ = sentinel;
    sentinel -> prev_ = sentinel;
    current = sentinel;
}

/**
 * Returns true if the Rolodex is positioned before the first card.
 */
bool Rolodex::isBeforeFirst() const
{
    // Replace with real code
    return (sentinel == current);
}

/**
 * Returns true if the Rolodex is positioned after the last card.
 */
bool Rolodex::isAfterLast() const
{
    // Replace with real code
    return (sentinel == current);
}

/**
 * Rotates the Rolodex one card forwards.
 */
void Rolodex::rotateForward()
{
    // Add code here
    current = current->next_;
}

/**
 * Rotates the Rolodex one card backwards.
 */
void Rolodex::rotateBackward()
{
    // Add code here
    current = current->prev_;
}

/**
 * Returns the value of the current card.
 */
const std::string& Rolodex::currentValue() const
{
	return current->value_;
}

/**
 * Inserts a new card after the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertAfterCurrent(const std::string& value)
{
    // Add code here
    RodolexItem* coming = new RodolexItem;

    coming->value_ = value;
    coming->next_ = current->next_;
    coming->prev_ = current;
    current->next_->prev_ = coming;
    current->next_ = coming;
    current = coming;
}

/**
 * Inserts a new card before the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertBeforeCurrent(const std::string& value)
{
    // Add code here
    RodolexItem* going = new RodolexItem;

    going -> value_ = value;
    going -> next_ = current;
    going -> prev_ = current-> prev_;
    current-> prev_ -> next_ = going;
    current-> prev_ = going;

    current = going;
}

 void Rolodex::delete_current()
 {
     //Add code here
     current-> prev_ -> next_ = current-> next_;
     current-> next_ -> prev_ = current-> prev_;
     RodolexItem* deleter = current;
     current = current-> next_;
     delete deleter;
 }
