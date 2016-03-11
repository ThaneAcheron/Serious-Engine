/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 4 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"

#include "StdH.h"
#include "ModelsMP/Enemies/Mental/Mental.h"

#include <EntitiesMP/BigHead.h>
#include <EntitiesMP/BigHead_tables.h>
#line 18 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"

// info structure
static EntityInfo eiMental = {
  EIBT_FLESH, 200.0f,
  0.0f, 1.5f, 0.0f,     // source (eyes)
  0.0f, 1.0f, 0.0f,     // target (body)
};

#define GREET_SENSE_RANGE 10.0f
#define GREET_SENSE_DELAY 30.0f


void CBigHead::SetDefaultProperties(void) {
  m_fnmHeadTex = CTString("");
  m_fnmNameSnd = CTString("");
  m_tmLastGreetTime = -100.0f;
  m_bhtType = BHT_NORMAL ;
  m_bIgnorePlayer = FALSE ;
  m_bPlayingWalkSound = FALSE ;
  m_bSleeping = FALSE ;
  m_tmLastWalkingSoundTime = -100.0f;
  m_tmWalkingSound = 5.0f;
  CEnemyBase::SetDefaultProperties();
}
  
#line 74 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
BOOL CBigHead::HandleEvent(const CEntityEvent & ee) 
#line 75 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
{
#line 76 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_bIgnorePlayer ){
#line 77 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(ee  . ee_slEvent  == EVENTCODE_ETouch ){
#line 78 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
ETouch  & et  = (ETouch  &) ee ;
#line 79 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(IsOfClass  (et  . penOther  , "Player")){
#line 80 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return TRUE ;
#line 81 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 82 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 83 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 84 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return CEnemyBase  :: HandleEvent  (ee );
#line 85 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 88 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void * CBigHead::GetEntityInfo(void) 
#line 89 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
{
#line 90 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return & eiMental ;
#line 91 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 93 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::Precache(void) 
#line 94 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
{
#line 95 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
CEnemyBase  :: Precache  ();
#line 96 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_SIGHT );
#line 97 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_IDLE );
#line 98 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_WOUND );
#line 99 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_DEATH );
#line 100 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_WALKZOMBIE );
#line 101 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_WALKSAINT );
#line 102 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_aps  . Precache  (m_fnmNameSnd );
#line 103 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_apt  . Precache  (m_fnmHeadTex );
#line 104 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 106 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
INDEX CBigHead::GetWalkAnim(void) 
#line 107 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
{
#line 108 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_bhtType  == BHT_ZOMBIE ){
#line 109 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return MENTAL_ANIM_WALKZOMBIE ;
#line 110 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}else if(m_bhtType  == BHT_SAINT ){
#line 111 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return MENTAL_ANIM_WALKANGEL ;
#line 112 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}else {
#line 113 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return MENTAL_ANIM_RUN ;
#line 114 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 115 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 118 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
INDEX CBigHead::AnimForDamage(FLOAT fDamage) {
#line 119 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
INDEX iAnim ;
#line 120 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
iAnim  = MENTAL_ANIM_PANIC ;
#line 121 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (iAnim  , 0);
#line 122 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return iAnim ;
#line 123 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 126 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
INDEX CBigHead::AnimForDeath(void) {
#line 127 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
INDEX iAnim ;
#line 128 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
iAnim  = MENTAL_ANIM_DEATH ;
#line 129 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (iAnim  , 0);
#line 130 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return iAnim ;
#line 131 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 133 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::DeathNotify(void) {
#line 135 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
en_fDensity  = 500.0f;
#line 136 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 139 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::StandingAnim(void) {
#line 140 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_GROUNDREST  , AOF_LOOPING  | AOF_NORESTART );
#line 141 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 142 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::WalkingAnim(void) {
#line 143 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlayWalkSound  ();
#line 144 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (GetWalkAnim  () , AOF_LOOPING  | AOF_NORESTART );
#line 146 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(! m_bIgnorePlayer  && _pTimer  -> CurrentTick  () > m_tmLastGreetTime  + GREET_SENSE_DELAY ){
#line 147 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = GREET_SENSE_RANGE ;
#line 148 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bDeaf  = FALSE ;
#line 149 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 150 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 151 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::RunningAnim(void) 
#line 152 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
{
#line 153 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlayWalkSound  ();
#line 154 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (GetWalkAnim  () , AOF_LOOPING  | AOF_NORESTART );
#line 155 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 156 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::RotatingAnim(void) {
#line 157 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
RunningAnim  ();
#line 158 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 160 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::PlayWalkSound(void) 
#line 161 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
{
#line 162 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
INDEX iSound  = SOUND_WALKZOMBIE ;
#line 163 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_bhtType  == BHT_ZOMBIE ){
#line 164 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
iSound  = SOUND_WALKZOMBIE ;
#line 165 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}else if(m_bhtType  == BHT_SAINT ){
#line 166 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
iSound  = SOUND_WALKSAINT ;
#line 167 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}else {
#line 168 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return ;
#line 169 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 170 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(! m_bPlayingWalkSound  || _pTimer  -> CurrentTick  () - m_tmLastWalkingSoundTime  > m_tmWalkingSound ){
#line 171 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = TRUE ;
#line 172 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_tmLastWalkingSoundTime  = _pTimer  -> CurrentTick  ();
#line 173 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , iSound  , SOF_3D );
#line 174 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 175 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 178 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::IdleSound(void) {
#line 179 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_bIgnorePlayer ){
#line 180 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return ;
#line 181 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 182 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 183 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 184 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 186 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::SightSound(void) {
#line 187 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 188 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 189 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 190 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::WoundSound(void) {
#line 191 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 192 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 193 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
  
#line 194 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
void CBigHead::DeathSound(void) {
#line 195 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 196 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 197 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
BOOL CBigHead::
#line 200 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 202 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(!(CalcDist  (m_penEnemy ) <= m_fStopDistance  * 1.1f)){ Jump(STATE_CURRENT,0x01540003, FALSE, EInternal());return TRUE;}
#line 203 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_fnmNameSnd  != ""){
#line 204 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , m_fnmNameSnd  , SOF_3D );
#line 205 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 206 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 207 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bBlind  = TRUE ;
#line 208 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bDeaf  = TRUE ;
#line 209 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = 0.0f;
#line 210 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_tmLastGreetTime  = _pTimer  -> CurrentTick  ();
#line 211 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetTargetNone  ();
#line 212 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_GREET  , 0);
#line 213 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetTimerAfter(GetModelObject  () -> GetCurrentAnimLength  ());
Jump(STATE_CURRENT, 0x01540001, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x01540001_Fire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01540002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBigHead::H0x01540002_Fire_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540002
;
#line 214 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StandingAnim  ();
#line 215 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReconsiderBehavior  ());
#line 215 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return TRUE;Jump(STATE_CURRENT,0x01540003, FALSE, EInternal());return TRUE;}BOOL CBigHead::H0x01540003_Fire_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540003

#line 217 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReturn  ());
#line 217 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 220 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Sleep(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_Sleep
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::Sleep expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 223 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_SNORE  , AOF_LOOPING );
#line 225 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x01540005, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x01540005_Sleep_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540005
switch(__eeInput.ee_slEvent){case(EVENTCODE_ETrigger):{const ETrigger&eTrigger= (ETrigger&)__eeInput;

#line 231 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Jump(STATE_CURRENT, STATE_CBigHead_WakeUp, TRUE, EVoid());return TRUE;
#line 232 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;default:{
#line 240 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return TRUE;
#line 241 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;
#line 242 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}return TRUE;}BOOL CBigHead::H0x01540006_Sleep_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540006
 ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 245 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
WakeUp(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_WakeUp
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::WakeUp expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 248 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SightSound  ();
#line 249 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_GETUP  , 0);
#line 250 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetTimerAfter(GetModelObject  () -> GetCurrentAnimLength  ());
Jump(STATE_CURRENT, 0x01540008, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x01540008_WakeUp_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540008
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01540009, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBigHead::H0x01540009_WakeUp_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540009
;
#line 255 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReturn  ());
#line 255 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 259 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
PreMainLoop(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_PreMainLoop
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::PreMainLoop expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 262 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(!(m_bSleeping )){ Jump(STATE_CURRENT,0x0154000d, FALSE, EInternal());return TRUE;}
#line 263 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bSleeping  = FALSE ;
#line 265 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x0154000b, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x0154000b_PreMainLoop_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0154000b
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 267 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Call(STATE_CURRENT, STATE_CBigHead_Sleep, TRUE, EVoid());return TRUE;
#line 268 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):{const EReturn&e= (EReturn&)__eeInput;

#line 270 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
UnsetTimer();Jump(STATE_CURRENT,0x0154000c, FALSE, EInternal());return TRUE;
#line 271 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&eDeath= (EDeath&)__eeInput;

#line 275 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_Die, FALSE, eDeath );return TRUE;
#line 276 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 277 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}return TRUE;}BOOL CBigHead::H0x0154000c_PreMainLoop_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0154000c
Jump(STATE_CURRENT,0x0154000d, FALSE, EInternal());return TRUE;}BOOL CBigHead::H0x0154000d_PreMainLoop_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0154000d

#line 279 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReturn  ());
#line 279 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 285 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 287 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
InitAsModel  ();
#line 288 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetPhysicsFlags  (EPF_MODEL_WALKING  | EPF_HASLUNGS );
#line 289 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetCollisionFlags  (ECF_MODEL );
#line 290 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 291 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetHealth  (20.0f);
#line 292 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fMaxHealth  = 20.0f;
#line 293 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
en_tmMaxHoldBreath  = 5.0f;
#line 294 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
en_fDensity  = 2000.0f;
#line 295 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fBlowUpSize  = 2.0f;
#line 298 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetModel  (MODEL_MENTAL );
#line 299 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
SetModelMainTexture  (TEXTURE_MENTAL );
#line 300 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
AddAttachment  (0 , MODEL_HEAD  , TEXTURE_MENTAL );
#line 301 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_fnmHeadTex  != ""){
#line 303 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
try {
#line 304 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
CAttachmentModelObject  * pamoHead  = GetModelObject  () -> GetAttachmentModel  (0);
#line 305 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(pamoHead  != NULL ){
#line 306 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
pamoHead  -> amo_moModelObject  . mo_toTexture  . SetData_t  (m_fnmHeadTex );
#line 307 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 309 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}catch  (char  * strError ){
#line 311 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
CPrintF  ("%s\n" , strError );
#line 312 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
AddAttachment  (0 , MODEL_HEAD  , TEXTURE_MENTAL );
#line 313 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 314 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 315 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_bhtType  == BHT_ZOMBIE ){
#line 316 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
AddAttachment  (MENTAL_ATTACHMENT_HORNS  , MODEL_HORNS  , TEXTURE_HORNS );
#line 317 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}else if(m_bhtType  == BHT_SAINT ){
#line 318 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
AddAttachment  (MENTAL_ATTACHMENT_AURA  , MODEL_AURA  , TEXTURE_AURA );
#line 319 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 322 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fWalkSpeed  = FRnd  () + 1.5f;
#line 323 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 10.0f + 500.0f);
#line 324 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fAttackRunSpeed  = FRnd  () * 2.0f + 6.0f;
#line 325 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 326 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fCloseRunSpeed  = FRnd  () * 2.0f + 6.0f;
#line 327 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 329 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fAttackDistance  = 50.0f;
#line 330 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fCloseDistance  = 0.0f;
#line 331 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fStopDistance  = 5.0f;
#line 332 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fAttackFireTime  = 0.1f;
#line 333 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fCloseFireTime  = 0.1f;
#line 334 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fIgnoreRange  = 200.0f;
#line 336 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fBlowUpAmount  = 65.0f;
#line 337 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fBodyParts  = 4;
#line 338 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fDamageWounded  = 1.0f;
#line 339 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_iScore  = 0;
#line 340 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
if(m_bIgnorePlayer ){
#line 341 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bBlind  = TRUE ;
#line 342 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bDeaf  = TRUE ;
#line 343 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = 0;
#line 344 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}else {
#line 345 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_bBlind  = TRUE ;
#line 346 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = GREET_SENSE_RANGE ;
#line 347 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
}
#line 350 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
const FLOAT fSize  = 0.6f;
#line 351 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
GetModelObject  () -> StretchModel  (FLOAT3D (fSize  , fSize  , fSize ));
#line 352 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
ModelChangeNotify  ();
#line 353 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
StandingAnim  ();
#line 356 "D:/SE1_GPL/Sources/EntitiesMP/BigHead.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};