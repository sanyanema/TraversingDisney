// include the Themeparks library
const Themeparks = require("themeparks");

// configure where SQLite DB sits
// optional - will be created in node working directory if not configured
// Themeparks.Settings.Cache = __dirname + "/themeparks.db";

// access a specific park
//  Create this *ONCE* and re-use this object for the lifetime of your application
//  re-creating this every time you require access is very slow, and will fetch data repeatedly for no purpose
const DisneyWorldMagicKingdom = new Themeparks.Parks.WaltDisneyWorldMagicKingdom();

// Access wait times by Promise
const CheckWaitTimes = () => {
    DisneyWorldMagicKingdom.GetWaitTimes().then((rideTimes) => {
        rideTimes.forEach((ride) => {
            console.log(`${ride.name}: ${ride.waitTime} minutes wait (${ride.status})`);
        });
    }).catch((error) => {
        console.error(error);
    }).then(() => {
        setTimeout(CheckWaitTimes, 1000 * 60 * 5); // refresh every 5 minutes
    });
};
CheckWaitTimes();

// you can also call GetOpeningTimes on themeparks objects to get park opening hours
