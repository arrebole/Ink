// 重构：内联类

namespace BadSmell {
    class TrackingInfomation {
        private _shippingCompany: string;
        private _trackingNumber: string;

        public get shippingCompany(): string {
            return this._shippingCompany;
        }
        public set shippingCompany(v: string) {
            this._shippingCompany = v;
        }
        public get trackingNumber(): string {
            return this._trackingNumber;
        }
        public set trackingNumber(v: string) {
            this._trackingNumber = v;
        }

        get display() {
            return `${this.shippingCompany}: ${this.trackingNumber}`
        }
    }

    class Shipment {
        private _TrackingInfomation: TrackingInfomation;
        public get TrackingInfomation(): TrackingInfomation {
            return this._TrackingInfomation;
        }
        public set TrackingInfomation(v: TrackingInfomation) {
            this._TrackingInfomation = v;
        }
        get trackingInfo() {
            return this._TrackingInfomation.display;
        }
    }
}

namespace GoodSmell {

    class Shipment {
        private _shippingCompany: string;
        private _trackingNumber: string;

        public get shippingCompany(): string {
            return this._shippingCompany;
        }
        public set shippingCompany(v: string) {
            this._shippingCompany = v;
        }
        public get trackingNumber(): string {
            return this._trackingNumber;
        }
        public set trackingNumber(v: string) {
            this._trackingNumber = v;
        }

        get trackingInfo() {
            return `${this.shippingCompany}: ${this.trackingNumber}`
        }
    }
}