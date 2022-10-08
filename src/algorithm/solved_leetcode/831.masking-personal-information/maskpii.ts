// origin: https://leetcode-cn.com/problems/masking-personal-information/

class PhoneMasker {
    private static readonly reg = /\D+/g;
    static isPhone(phone: string) {
        return phone.replace(PhoneMasker.reg, '').length >= 10;
    }
    static mask(phone: string) {
        const phoneNumber = phone.replace(PhoneMasker.reg, '');
        if (phoneNumber.length === 10) {
            return `***-***-${phoneNumber.substr(-4, 4)}`;
        }
        return `+${'*'.repeat(phoneNumber.length-10)}-***-***-${phoneNumber.substr(-4, 4)}`
    }
}

class EmailMasker {
    private static readonly reg = /(\w+)@(\w+)\.(\w+)/;

    static isEmail(email: string) {
        if (!EmailMasker.reg.test(email)) return false;
        if (email.split('@')[0]?.length < 2) return false;
        return true
    }

    static mask(email: string) {
        const names = EmailMasker.reg.exec(email)!;
        return `${names[1].charAt(0)}*****${names[1].charAt(names[1].length - 1)}@${names[2]}.${names[3]}`
            .toLocaleLowerCase();
    }
}

function maskPII(S: string): string {
    if (PhoneMasker.isPhone(S)) {
        return PhoneMasker.mask(S);
    }
    if (EmailMasker.isEmail(S)) {
        return EmailMasker.mask(S);
    }
    throw new Error('Not supper type')
};
