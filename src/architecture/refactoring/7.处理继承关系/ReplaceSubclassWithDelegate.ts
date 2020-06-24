// 重构：以委托取代子类

namespace BadSmell {
    class Booking{
        constructor(show,date){
            this._show = show
            this._date = date
        }
        protected _show;
        protected _date;
        protected isPeakDay;

        get hasTalkback(){
            return this._show.hasOwnProperty('talkback') && !this.isPeakDay;
        }

        get basePrice(){
            let result = this._show.price;
            if(this.isPeakDay) result +=Math.round(result *0.15);
            return result;
        }
    }

    class PremiumBooking extends Booking{
        constructor(show,date,extras){
            super(show,date);
            this._extras = extras
        }
        private _extras;

        get hasTalkback(){
            return this._show.hasOwnProperty('talkback')
        }

        get basePrice(){
            return Math.round(super.basePrice + this._extras.premiumFee);
        }
    }
}
namespace GoodSmell {
    function createPremiumBooking(show,date,extras){
        const result = new Booking(show,date)
        result._bePremium(extras)
        return result;
    }
    class Booking{
        constructor(show,date){
            this._show = show
            this._date = date
        }
        _show;
        protected _date;
        protected isPeakDay;
        protected _premiumDelegate:PremiumBookingDelegate;
        
        _bePremium(extras){
            this._premiumDelegate = new PremiumBookingDelegate(this,extras)
        }
        get hasTalkback(){
            return (this._premiumDelegate)
                ?this._premiumDelegate.hasTalkback
                :this._show.hasOwnProperty('talkback') && !this.isPeakDay;
        }

        get basePrice(){
            return (this._premiumDelegate)
                ?this._premiumDelegate.basePrice
                :this._privateBasePrice
        }
        get _privateBasePrice(){
            let result = this._show.price;
            if(this.isPeakDay) result += Math.round(result * 0.15)
            return result;
        }
    }
    class PremiumBookingDelegate{
        constructor(hostBooking,extras){
            this._host = hostBooking;
            this._extras = extras
        }
        protected _host:Booking;
        protected _extras;

        get hasTalkback(){
            return this._host._show.hasOwnProperty('talkback')
        }
        get basePrice(){
            return Math.round(this._host._privateBasePrice + this._extras.premiumFee);
        }
    }
}