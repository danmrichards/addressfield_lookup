<?php

/**
 * @file
 * Contains the PCAPredictAdapter class.
 */

/**
 * Adapater for the PCAPredict API.
 */
class PCAPredictAdapter extends PCAPredict {

  /**
   * List of PCA Predict API endpoints. Keyed by their name.
   *
   * @var array
   *
   * @see http://www.pcapredict.com/support/webservices
   */
  private $endpoints = array(
    'Find' => 'CapturePlus/Interactive/Find/v2.10',
    'Retrieve' => 'CapturePlus/Interactive/Retrieve/v2.10',
  );

  /**
   * Find addresses matching the search term.
   *
   * @param string $term
   *   The search term.
   *
   * @return mixed
   *   Array of addresses or FALSE;
   */
  public function find($term) {
    // Build array of parameters to pass to the API.
    $params = array(
      'SearchTerm' => $term,
      'Filter' => $this->filter,
    );

    // Get the raw API result.
    $api_response = $this->callApi($this->endpoints['Find'], $params);

    // Bail out if there was no response.
    if (!isset($api_response)) {
      return FALSE;
    }

    // Parse the API repsonse.
    return $this->parseApiResponse($api_response);
  }

  /**
   * Returns the full address details based on the Id.
   *
   * @param string $id
   *   The ID of the address.
   *
   * @return mixed
   *   The address details or FALSE.
   */
  public function retrieve($id) {
    // Get the raw API result.
    $api_response = $this->callApi($this->endpoints['Retrieve'], array('Id' => $id));

    // Bail out if there was no response.
    if (!isset($api_response)) {
      return FALSE;
    }

    // Parse the API repsonse.
    return $this->parseApiResponse($api_response);
  }

}
