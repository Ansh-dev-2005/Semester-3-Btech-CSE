
public class PatientMicroservice {

    private Map<Integer, Patient> patients = new HashMap<>();

    public Patient getPatient(int patientId) {
        return patients.get(patientId);
    }

    public int createPatient(Patient patient) {
        int patientId = patients.size() + 1;
        patients.put(patientId, patient);
        return patientId;
    }

    public void updatePatient(int patientId, Patient patient) {
        patients.put(patientId, patient);
    }

    public void deletePatient(int patientId) {
        patients.remove(patientId);
    }

    public static void main(String[] args) {
        PatientMicroservice microservice = new PatientMicroservice();

        // Create a new patient
        Patient patient = new Patient();
        patient.setName("John Doe");
        patient.setAge(30);
        patient.setAddress("123 Main Street");
        patient.setPhoneNumber("(123) 456-7890");
        int patientId = microservice.createPatient(patient);

        // Get the patient data
        patient = microservice.getPatient(patientId);

        // Update the patient data
        patient.setPhoneNumber("(987) 654-3210");
        microservice.updatePatient(patientId, patient);

        // Delete the patient
        microservice.deletePatient(patientId);
    }
}