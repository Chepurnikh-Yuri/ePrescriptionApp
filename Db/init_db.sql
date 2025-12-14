CREATE TABLE IF NOT EXISTS doctor (
	id BIGSERIAL PRIMARY KEY,
	first_name VARCHAR(50) NOT NULL,
	second_name VARCHAR(50) NOT NULL,
	last_name VARCHAR(50) NOT NULL,
	specialization TEXT NOT NULL,
	hospital TEXT NOT NULL
);

CREATE TYPE gender AS ENUM ('female', 'male');

CREATE TABLE IF NOT EXISTS patient (
	id BIGSERIAL PRIMARY KEY,
	first_name VARCHAR(50) NOT NULL,
	second_name VARCHAR(50) NOT NULL,
	last_name VARCHAR(50) NOT NULL,
	gender gender NOT NULL,
	birth_date DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS recipe (
	id BIGSERIAL PRIMARY KEY,
	patient_id BIGINT NOT NULL,
	doctor_id BIGINT NOT NULL,
	date_of_issue DATE NOT NULL,
	drug VARCHAR(50) NOT NULL,
	dosage TEXT NOT NULL,
	admission_procedure TEXT NOT NULL,
	course_duration INT NOT NULL,
	FOREIGN KEY (patient_id) REFERENCES patient(id) ON DELETE CASCADE,
	FOREIGN KEY (doctor_id) REFERENCES doctor(id) ON DELETE CASCADE
);


