-- Keep a log of any SQL queries you execute as you solve the mystery.

-- figuring out the id of the crime scene where the theft happened and open the description
select id,description from crime_scene_reports 
where year == 2020 
and day == 28 
and month == 7
and street = 'Chamberlin Street';

select * from crime_scene_reports where street = 'Chamberlin Street';

select * from interviews where transcript like '%courthouse%' and day = 28 and month = 7;

--ruth: within ten mins of theft check cars leaving parking lot of courthouse (3)
-- eugene: on the theft morning he saw the theif withdrawing money from atm on Fifer Street (1)
-- raymond: he talked on the phone call lasted less than a minute asked the other person to purchase the flight ticket 
--         and said that he would take the earliest flight out of fiftyville tomorrow 29/7/2020 (2)

select account_number from atm_transactions where day == 28 and month == 7 and
atm_location='Fifer Street' and transaction_type = 'withdraw';
--28500762 28296815 76054385 49610011 16153065 25506511 81061156 26013199
select * from people where id in (select person_id from bank_accounts where 
   account_number in (select account_number from atm_transactions where 
    day == 28 and month == 7 and
   atm_location='Fifer Street' and transaction_type = 'withdraw'));
   
--395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
--396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
--438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
--458378 | Roy | (122) 555-4581 | 4408372428 | QX4YZN3
--467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
--514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X 

select * from courthouse_security_logs where day == 28 and month == 7 and year== 2020
and activity == 'exit' and hour == 10
and minute between 15 and 25 and license_plate in (
select license_plate from people where id in 
(select person_id from bank_accounts where 
   account_number in (select account_number from atm_transactions where 
    day == 28 and month == 7 and
   atm_location='Fifer Street' and transaction_type = 'withdraw')));
--id | year | month | day | hour | minute | activity | license_plate
--261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X. Ernest | (367) 555-5533 | 5773159633 
--263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8. Danielle | (389) 555-5198 | 8496433585 thief
--265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ. Elizabeth | (829) 555-5269 | 7049073643
--266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE. Russell | (770) 555-1861 | 3592750733 

select * from airports;
--8 | CSF | Fiftyville Regional Airport | Fiftyville

select * from flights where month == 7 and day == 29 and year == 2020 and origin_airport_id in (select 
id from airports where abbreviation ='CSF');
-- earliest flight id = 36 from airport 8 to airport 4
select * from passengers where flight_id == 36; 
-- theif seat = 7B same passport number from taken above
-- airport is London where its airport id is 4
select * from phone_calls;

select * from phone_calls where caller = '(389) 555-5198' or receiver='(389) 555-5198';

select name from people where phone_number='(609) 555-5876';

--id | name | phone_number | passport_number | license_plate
--467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8

select caller,receiver from phone_calls where duration < 60 and day == 28 and month == 7;
caller | receiver
(130) 555-0289 | (996) 555-8899
(499) 555-9472 | (892) 555-8872
(367) 555-5533 | (375) 555-8161
(499) 555-9472 | (717) 555-1342
(286) 555-6063 | (676) 555-6554
(770) 555-1861 | (725) 555-3243
(031) 555-6622 | (910) 555-3251
(826) 555-1652 | (066) 555-9701
(338) 555-6650 | (704) 555-2131

select *from people where id in (select person_id from bank_accounts where 
   account_number in (select account_number from atm_transactions where 
    day == 28 and month == 7 and
   atm_location='Fifer Street' and transaction_type = 'withdraw'));
   phone_number
id | name | phone_number | passport_number | license_plate

514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X

--cars that left on that timeframe

id | name | phone_number | passport_number | license_plate
--221103 | Patrick | (725) 555-4692 | 2963008352 | 5P2BI95 not theif
--398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7  maybe
--514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE not theif
--560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55  maybe 
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X  maybe 
