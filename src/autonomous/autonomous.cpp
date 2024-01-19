#include "main.h"

thunderbird::Auton::Auton(Drive _drive, Kicker kicker, Intake _intake, Wings _wings, Elevation _elevation, Blocker _blocker)  :
  _drive(_drive),
  _kicker(kicker),
  _intake(_intake),
  _wings(_wings),
  _elevation( _elevation),
  _blocker( _blocker)
{};