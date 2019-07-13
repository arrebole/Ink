// 重构：以命令取代函数

namespace BadSmell {
    function score(candidate, medicalExam, scoringGuide) {
        let result = 0;
        let healthLevel = 0;
        let highMedicalRiskFlag = false;

        if (medicalExam.isSmoker) {
            healthLevel += 10;
            highMedicalRiskFlag = true;
        }

        let certificationGrade = "regular"
        if (scoringGuide.stateWithLowCertification(candidate.originState)) {
            certificationGrade = "low";
            result -= 5;
        }
        result -= Math.max(healthLevel - 5, 0);
        return result;
    }
}
namespace GoodSmell {
    class Score {
        private candidate
        private medicalExam
        private scoringGuide
        private healthLevel
        private result
        private highMedicalRiskFlag
        private certificationGrade

        constructor(candidate, medicalExam, scoringGuide) {
            this.candidate = candidate;
            this.medicalExam = medicalExam;
            this.scoringGuide = scoringGuide;
        }
        scroeSmoking() {
            if (this.medicalExam.isSmoker) {
                this.healthLevel += 10;
                this.highMedicalRiskFlag = true;
            }
        }
        execute() {
            this.result = 0;
            this.healthLevel = 0;
            this.highMedicalRiskFlag = false;

            this.scroeSmoking()
            this.certificationGrade = "regular"
            if (this.scoringGuide.stateWithLowCertification(this.candidate.originState)) {
                this.certificationGrade = "low";
                this.result -= 5;
            }
            this.result -= Math.max(this.healthLevel - 5, 0);
            return this.result;
        }
    }

    function score(candidate, medicalExam, scoringGuide) {
        return new Score(candidate, medicalExam, scoringGuide).execute()
    }
}