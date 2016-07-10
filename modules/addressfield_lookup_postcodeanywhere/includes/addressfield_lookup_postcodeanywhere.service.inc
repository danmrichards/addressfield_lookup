<?php

/**
 * @file
 * Contains AddressFieldLookupPostcodeAnywhere.
 */

/**
 * Address Field Lookup service for Postcode anywhere.
 */
class AddressFieldLookupPostcodeAnywhere implements AddressFieldLookupInterface {

  /**
   * API Adapter for PCA Predict.
   *
   * @var PCAPredict
   *
   * @see PCAPredictAdapter
   * @see PCAPredict
   */
  protected $api;

  /**
   * Constructor.
   *
   * @param PCAPredict $api
   *   An instantiated API adapater.
   */
  public function __construct(PCAPredict $api) {
    $this->api = $api;
  }

  /**
   * {@inheritdoc}
   */
  public function lookup($term) {
    // Get the API result.
    $api_response = $this->api->find($term);

    if (!is_array($api_response)) {
      return FALSE;
    }

    // Build the format we need.
    $results = array();

    foreach ($api_response as $api_response_item) {
      $result = array(
        'id' => $api_response_item->Id,
        'street' => trim(preg_replace("/{$term}\,/si", '', $api_response_item->Text)),
        'place' => '',
      );

      // If the API result indicated another 'Find' operation is needed, append
      // a marker to the result ID.
      if ($api_response_item->Next == 'Find') {
        $result['id'] .= '|Find';
      }

      $results[] = $result;
    }

    return $results;
  }

  /**
   * {@inheritdoc}
   */
  public function getAddressDetails($address_id) {
    // Get the API result.
    $api_response = $this->api->retrieve($address_id);

    if (!is_array($api_response)) {
      return FALSE;
    }

    // Address details array.
    $address_details = array(
      'id' => $address_id,
    );

    // Sub premise.
    if (!empty($api_response[0]->SubBuilding)) {
      $address_details['sub_premise'] = $api_response[0]->SubBuilding;
    }

    // Premise.
    $address_details['premise'] = '';

    // Premise: Check for building number.
    if (!empty($api_response[0]->BuildingNumber)) {
      $address_details['premise'] .= $api_response[0]->BuildingNumber . ' ';
    }

    // Premise: Check for building name.
    if (!empty($api_response[0]->BuildingName)) {
      $address_details['premise'] .= $api_response[0]->BuildingName . ' ';
    }

    // Premise: Remove white space.
    $address_details['premise'] = trim($address_details['premise']);

    // Thoroughfare.
    $address_details['thoroughfare'] = '';

    // Thoroughfare: Street 1.
    if (!empty($api_response[0]->Street)) {
      $address_details['thoroughfare'] .= $api_response[0]->Street . ' ';
    }

    // Thoroughfare: Street 2.
    if (!empty($api_response[0]->SecondaryStreet)) {
      $address_details['thoroughfare'] .= $api_response[0]->SecondaryStreet . ' ';
    }

    // Premise: Remove white space.
    $address_details['thoroughfare'] = trim($address_details['thoroughfare']);

    // Dependent locality: Administrative area.
    if (!empty($api_response[0]->AdminAreaName)) {
      $address_details['dependent_locality'] = $api_response[0]->AdminAreaName;
    }

    // Locality.
    $address_details['locality'] = isset($api_response[0]->City) ? $api_response[0]->City : '';

    // Postal code.
    $address_details['postal_code'] = isset($api_response[0]->PostalCode) ? $api_response[0]->PostalCode : '';

    // Administrative area.
    $address_details['administrative_area'] = isset($api_response[0]->Province) ? $api_response[0]->Province : '';

    // Organisation name.
    $address_details['organisation_name'] = isset($api_response[0]->Company) ? $api_response[0]->Company : '';

    return $address_details;
  }

}
