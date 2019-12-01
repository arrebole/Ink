// 重构：封装记录


namespace BadSmell {
    const organization = { name: "Acme Gooseberries", country: "GB" }
}


namespace GoodSmell {

    class Organization {
        constructor(organization: { name: string, country: string }) {
            this._name = organization.name;
            this._country = organization.country;
        }
        private _name: string
        private _country: string

        get name(): string { return this._name }
        get country(): string { return this._country }
        set name(aName: string) { this._name = aName }
        set country(aCountry: string) { this._country = aCountry }
    }

    const organization = new Organization({ name: "Acme Gooseberries", country: "GB" })

    export function getOrganization() {
        return organization;
    }


}